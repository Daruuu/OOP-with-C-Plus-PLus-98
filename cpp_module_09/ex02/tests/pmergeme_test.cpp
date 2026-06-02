/**
 * @file pmergeme_test.cpp
 * @brief GoogleTest suite for PmergeMe (Ford-Johnson sort).
 *
 * Build:  cd tests && make setup && make && ./run_tests
 * Or:     cd ex02 && make test
 *
 * GoogleTest lives in ../extern/googletest (downloaded by tests/Makefile).
 *
 * Test categories:
 *   1. Basic cases       — 1, 2, 3 elements
 *   2. Input validation  — invalid chars, already sorted (custom rule)
 *   3. Large sort        — 100 unique numbers (compare with std::sort)
 *
 * Each test follows Arrange / Act / Assert (Given / When / Then).
 */

#include <gtest/gtest.h>
#include "../PmergeMe.hpp"

#include <algorithm>
#include <list>
#include <sstream>
#include <vector>

//  Helpers

/** Suppresses std::cout output for the duration of its lifetime. */
struct SuppressStdout
{
	std::streambuf* old_;

	SuppressStdout() : old_(std::cout.rdbuf(nullptr))
	{
	}

	~SuppressStdout() { std::cout.rdbuf(old_); }
};

/** Suppresses std::cerr output for the duration of its lifetime. */
struct SuppressStderr
{
	std::streambuf* old_;

	SuppressStderr() : old_(std::cerr.rdbuf(nullptr))
	{
	}

	~SuppressStderr() { std::cerr.rdbuf(old_); }
};

/**
 * Converts a vector<int> into the argv-style buffers that processSequence needs.
 * @param nums      source integers
 * @param strBuf    keeps the std::string objects alive
 * @param argvBuf   keeps the char* pointers alive
 */
static void buildArgs(const std::vector<int>& nums,
					std::vector<std::string>& strBuf,
					std::vector<char*>& argvBuf)
{
	strBuf.clear();
	argvBuf.clear();
	for (size_t i = 0; i < nums.size(); ++i)
	{
		std::ostringstream oss;
		oss << nums[i];
		strBuf.push_back(oss.str());
	}
	for (size_t i = 0; i < strBuf.size(); ++i)
		argvBuf.push_back(&strBuf[i][0]);
}

/** Returns true when a std::vector<int> is sorted in non-decreasing order. */
static bool isSorted(const std::vector<int>& v)
{
	for (size_t i = 1; i < v.size(); ++i)
		if (v[i] < v[i - 1])
			return false;
	return true;
}

/** Returns true when a std::list<int> is sorted in non-decreasing order. */
static bool isSorted(const std::list<int>& l)
{
	std::list<int>::const_iterator prev = l.begin();
	if (prev == l.end())
		return true;
	std::list<int>::const_iterator curr = prev;
	++curr;
	for (; curr != l.end(); ++prev, ++curr)
		if (*curr < *prev)
			return false;
	return true;
}

/**
 * Runs parse + sort like the real program, without printing to the terminal.
 */
static bool parseAndRun(PmergeMe& pm, int argc, char** argv)
{
	SuppressStdout suppressOut;
	SuppressStderr suppressErr;
	if (!pm.parseArguments(argc, argv))
		return false;
	pm.run();
	return true;
}

/**
 * Builds N unique positive integers that are NOT already sorted ascending.
 * Uses  N..1 (reverse order) so tests stay deterministic (same input every run).
 */
static std::vector<int> makeInput1ToNReverse(size_t count)
{
	std::vector<int> nums;
	nums.reserve(count);
	for (size_t i = count; i >= 1; --i)
		nums.push_back(static_cast<int>(i));
	return nums;
}

// -----------------------------------------------------------------------------
//  Large sort — 100 numbers
// -----------------------------------------------------------------------------

/**
 * Fixture: shared buffers for argv-style arguments.
 * Junior tip: strBuf_ must live while the test runs (char* point into strings).
 */
class PmergeMeSort100Test : public ::testing::Test
{
protected:
	PmergeMe pm_;
	std::vector<std::string> strBuf_;
	std::vector<char*> argvBuf_;

	void runSort(const std::vector<int>& input)
	{
		buildArgs(input, strBuf_, argvBuf_);
		ASSERT_TRUE(parseAndRun(
			pm_, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	}
};

TEST_F(PmergeMeSort100Test, Sorts100UniqueNumbersLikeStdSort)
{
	// Arrange — 100 unique ints, not ascending (parse accepts this)
	const size_t count = 100;
	std::vector<int> input = makeInput1ToNReverse(count);
	std::vector<int> expected = input;
	std::sort(expected.begin(), expected.end());

	// Act — same path as ./PmergeMe n1 n2 ...
	runSort(input);

	// Assert
	const std::vector<int>& result = pm_.getSortedVector();
	ASSERT_EQ(result.size(), count);
	EXPECT_TRUE(isSorted(result));
	EXPECT_EQ(result, expected);
	EXPECT_TRUE(isSorted(pm_.getSortedList()));
}

// -----------------------------------------------------------------------------
//  Basic & validation
// -----------------------------------------------------------------------------

// 1. One element (caso base)
TEST(PmergeMeBasic, OneElement)
{
	// ARRANGE
	PmergeMe pm;
	char* argv[] = {(char*)"42"};

	// Act
	ASSERT_TRUE(parseAndRun(pm, 1, argv));

	// Assert
	const std::vector<int>& result = pm.getSortedVector();

	EXPECT_EQ(result.size(), 1u);
	EXPECT_EQ(result[0], 42);
}

// 2. Two elements (swap básico)
TEST(PmergeMeBasic, TwoElements)
{
	// ARRANGE
	PmergeMe pm;
	char* argv[] = {(char*)"9", (char*)"1"};

	// Act
	ASSERT_TRUE(parseAndRun(pm, 2, argv));

	// Assert
	const std::vector<int>& result = pm.getSortedVector();
	ASSERT_EQ(result.size(), 2u);
	EXPECT_EQ(result[0], 1);
	EXPECT_EQ(result[1], 9);
}


// 3. Three elements (caso impar)
TEST(PmergeMeBasic, ThreeElements)
{
	// ARRANGE
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"1", (char*)"3"};

	// Act
	ASSERT_TRUE(parseAndRun(pm, 3, argv));

	// Assert
	const std::vector<int>& result = pm.getSortedVector();
	EXPECT_TRUE(isSorted(result));
	EXPECT_EQ(result[0], 1);
	EXPECT_EQ(result[1], 3);
	EXPECT_EQ(result[2], 5);
}

// -----------------------------
// 4. Invalid input (carácter)
// -----------------------------

TEST(PmergeMeValidation, InvalidCharacter)
{
	// ARRANGE
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"a", (char*)"3"};

	// WHEN
	// SuppressStdout ss;
	// SuppressStderr se;

	bool ok = pm.parseArguments(3, argv);

	// THEN
	EXPECT_FALSE(ok);
}


// ─────────────────────────────────────────────
// 5. Already sorted input rejected
// ─────────────────────────────────────────────
TEST(PmergeMeValidation, AlreadySorted)
{
	// ARRANGE
	PmergeMe pm;
	char* argv[] = {(char*)"1", (char*)"2", (char*)"3", (char*)"4"};

	// WHEN
	SuppressStdout ss;
	SuppressStderr se;

	bool ok = pm.parseArguments(4, argv);

	// THEN
	EXPECT_FALSE(ok);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
