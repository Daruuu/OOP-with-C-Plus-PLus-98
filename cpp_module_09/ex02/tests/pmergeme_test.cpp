#include <gtest/gtest.h>
#include "../PmergeMe.hpp"
#include "../Utils.hpp"

// Prueba básica para comprobar que GoogleTest funciona en el proyecto
TEST(PmergeMeTest, InitialSanityCheck)
{
	EXPECT_TRUE(true);
}

TEST(PmergeMeTest, HandleInvalidCharacters)
{
	//	Arrange (preparar el escenario)
	PmergeMe pmerge_me;

	char* mockArgv[] = {
		(char *) "12",
		(char *) "3",
		(char *) "9",
		(char *) "5",
		(char *) "o"
	};
	int	mockArgc = std::size(mockArgv);

	//	Act (ejecutar function to test)
	const auto result = pmerge_me.processSequence(mockArgc, mockArgv);

	//	Then (check result)
	EXPECT_FALSE(result);
}

TEST(PmergeMeTest, HandleNegativeNumbers)
{
	// Arrange
	PmergeMe pmerge_me;

	char* mockArgv[] = {
		(char *) "12",
		(char *) "3",
		(char *) "9",
		(char *) "5",
		(char *) "20000",
		(char *) "-1"
	};
	int mockArgc = std::size(mockArgv);

	// Act
	const auto result = pmerge_me.processSequence(mockArgc, mockArgv);
	// Then
	EXPECT_FALSE(result);
}

TEST(PmergeMeTest, HandleMaxIntegerNumber)
{
	//	Arrange
	PmergeMe pmerge_me;
	char* mockArgv[] = {
		(char *) "12",
		(char *) "3",
		(char *) "9",
		(char *) "5",
		(char *) "20000",
		(char *) "2147483647"
	};
	int mockArgc = std::size(mockArgv);

	// Act
	const auto result = pmerge_me.processSequence(mockArgc, mockArgv);
	// Then
	EXPECT_TRUE(result);
}

TEST(PmergeMeTest, HandleOverflowIntegerNumber)
{
	//	Arrange
	PmergeMe pmerge_me;
	char* mockArgv[] = {
		(char *) "12",
		(char *) "3",
		(char *) "9",
		(char *) "5",
		(char *) "20000",
		(char *) "2147483647",
		(char *) "2147483648"
	};
	int mockArgc = std::size(mockArgv);

	// Act
	const auto result = pmerge_me.processSequence(mockArgc, mockArgv);
	// Then
	EXPECT_FALSE(result);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
