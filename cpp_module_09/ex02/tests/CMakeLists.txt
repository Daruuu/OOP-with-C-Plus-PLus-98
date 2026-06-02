# ─────────────────────────────────────────────────────────────────────────────
#  PmergeMe — Test Suite (GoogleTest)
#
#  GTest requiere C++11 como mínimo. Compilamos los tests en C++17
#  (por comodidad con std::size, etc.), pero PmergeMe.cpp sigue siendo
#  código válido C++98 y compila sin problema bajo C++17.
# ─────────────────────────────────────────────────────────────────────────────

# ── 1. Localizar GoogleTest instalado en el sistema (libgtest-dev) ──────────
find_package(GTest REQUIRED)

# ── 2. Registrar el runner de CTest (activa `ctest` y el panel de CLion) ────
enable_testing()

# ── 3. Definir el ejecutable de tests ───────────────────────────────────────
#   - pmergeme_test.cpp : archivo de tests
#   - ../PmergeMe.cpp   : código de producción (sin main.cpp)
add_executable(pmergeme_tests
    pmergeme_test.cpp
    ../PmergeMe.cpp
)

# ── 4. Incluir las cabeceras del directorio padre ────────────────────────────
target_include_directories(pmergeme_tests PRIVATE ..)

# ── 5. Estándar de C++ para este target (C++17 para los tests) ──────────────
set_target_properties(pmergeme_tests PROPERTIES
    CXX_STANDARD          17
    CXX_STANDARD_REQUIRED ON
)

# ── 6. Flags de compilación ──────────────────────────────────────────────────
target_compile_options(pmergeme_tests PRIVATE -Wall -Wextra)

# ── 7. Enlazar con GTest + pthread ───────────────────────────────────────────
#   GTest::gtest      → librería principal
#   GTest::gtest_main → provee el main() de GTest (podemos omitir el nuestro)
#   Nota: dejamos nuestro main() en pmergeme_test.cpp, así que usamos
#         GTest::gtest (sin _main) y pthread explícitamente.
target_link_libraries(pmergeme_tests
    PRIVATE
        GTest::gtest
        pthread
)

# ── 8. Registrar el test con CTest ───────────────────────────────────────────
#   Esto permite ejecutar todos los tests con: ctest --test-dir build/
add_test(NAME PmergeMeTests COMMAND pmergeme_tests)
