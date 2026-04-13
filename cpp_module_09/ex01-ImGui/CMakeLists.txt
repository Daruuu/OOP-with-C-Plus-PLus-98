cmake_minimum_required(VERSION 3.16)
project(RPN_ImGui_Visualizer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==================== FetchContent (todo automático) ====================
include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.4
)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG        v1.91.8
)

FetchContent_MakeAvailable(glfw imgui)

# ==================== ImGui sources ====================
file(GLOB IMGUI_SOURCES
        ${imgui_SOURCE_DIR}/*.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(RPN_ImGui
        main.cpp
        ${IMGUI_SOURCES}
)

target_include_directories(RPN_ImGui PRIVATE
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
)

target_link_libraries(RPN_ImGui PRIVATE glfw)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(RPN_ImGui PRIVATE OpenGL::GL)
