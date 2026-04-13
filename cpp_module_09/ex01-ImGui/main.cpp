#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>

struct Step {
    std::string token;
    std::vector<int> stackState;
};

class RPNVisualizer {
public:
    std::vector<Step> history;
    std::string expression;
    int currentStep = 0;
    bool autoPlay = false;
    float speed = 0.8f;

    void reset() {
        history.clear();
        currentStep = 0;
        autoPlay = false;
    }

    bool evaluate(const std::string& expr) {
        reset();
        std::stack<int> stk;
        std::istringstream iss(expr);
        std::string token;

        while (iss >> token) {
            if (token.size() == 1 && std::isdigit(token[0])) {
                int num = token[0] - '0';
                stk.push(num);
            } else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                if (stk.size() < 2) return false;

                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                int result = 0;
                if (token[0] == '+') result = a + b;
                else if (token[0] == '-') result = a - b;
                else if (token[0] == '*') result = a * b;
                else if (token[0] == '/') {
                    if (b == 0) return false;
                    result = a / b;
                }
                stk.push(result);
            } else {
                return false; // carácter inválido
            }

            // Guardar estado
            Step s;
            s.token = token;
            std::vector<int> temp;
            std::stack<int> copy = stk;
            while (!copy.empty()) {
                temp.push_back(copy.top());
                copy.pop();
            }
            std::reverse(temp.begin(), temp.end());
            s.stackState = temp;
            history.push_back(s);
        }

        return history.back().stackState.size() == 1;
    }
};

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1000, 700, "RPN Visualizer - Dear ImGui", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    RPNVisualizer viz;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("RPN Visualizer", nullptr, ImGuiWindowFlags_NoCollapse);

        ImGui::InputText("Expression", &viz.expression, ImGuiInputTextFlags_CharsUppercase);

        if (ImGui::Button("Evaluate")) {
            if (!viz.evaluate(viz.expression)) {
                ImGui::OpenPopup("Error");
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("Reset")) viz.reset();

        ImGui::SameLine();
        ImGui::Checkbox("Auto Play", &viz.autoPlay);

        if (viz.autoPlay) {
            ImGui::SliderFloat("Speed", &viz.speed, 0.1f, 2.0f);
        }

        ImGui::Separator();

        // Mostrar historial de pasos
        ImGui::Text("Steps: %zu", viz.history.size());
        for (int i = 0; i < static_cast<int>(viz.history.size()); ++i) {
            const auto& step = viz.history[i];
            bool isCurrent = (i == viz.currentStep);

            if (isCurrent) ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 0, 255));

            ImGui::Text("Step %2d | Token: %s", i + 1, step.token.c_str());

            ImGui::SameLine(200);
            ImGui::Text("Stack: [");
            for (size_t j = 0; j < step.stackState.size(); ++j) {
                ImGui::SameLine();
                ImGui::Text("%d", step.stackState[j]);
                if (j < step.stackState.size() - 1) ImGui::SameLine();
            }
            ImGui::Text("]");

            if (isCurrent) ImGui::PopStyleColor();
        }

        // Stack final grande y bonito
        if (!viz.history.empty()) {
            ImGui::Separator();
            ImGui::TextColored(ImVec4(0, 1, 0, 1), "FINAL STACK");
            const auto& finalStack = viz.history.back().stackState;
            for (int num : finalStack) {
                ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f), "   %d", num);
            }
        }

        ImGui::End();

        // Popup de error
        if (ImGui::BeginPopupModal("Error", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::Text("Invalid expression!");
            if (ImGui::Button("OK")) ImGui::CloseCurrentPopup();
            ImGui::EndPopup();
        }

        // Render
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}