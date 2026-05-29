#include <gtest/gtest.h>
#include "../PmergeMe.hpp"
#include "../Utils.hpp"

// Prueba básica para comprobar que GoogleTest funciona en el proyecto
TEST(PmergeMeTest, InitialSanityCheck) {
    EXPECT_TRUE(true);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
