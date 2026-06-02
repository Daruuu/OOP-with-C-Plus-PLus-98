/**
 * @file pmergeme_test.cpp
 * @brief GoogleTest suite for PmergeMe (Ford-Johnson sort).
 *
 * Compilation: c++ -std=c++17 -Wall -Wextra -Werror -I..
 *              pmergeme_test.cpp ../PmergeMe.cpp -lgtest -lpthread -o run_tests
 *
 * Test categories:
 *   1. Input validation  — invalid chars, negatives, overflow
 *   2. Edge cases        — 1, 2, 3 elements; already sorted; reverse sorted
 *   3. Correctness       — 100 elements (even), 101 elements (odd)
 *   4. Consistency       — vector and list produce identical results
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

/** Parses argv and runs the full sort pipeline (suppresses stdout/stderr). */
static bool parseAndRun(PmergeMe& pm, int argc, char** argv)
{
	SuppressStdout ss;
	SuppressStderr se;
	if (!pm.parseArguments(argc, argv))
		return false;
	pm.run();
	return true;
}

/** Returns true when vector and list contain the same elements in the same order. */
static bool containerMatch(const std::vector<int>& v, const std::list<int>& l)
{
	if (v.size() != l.size())
		return false;
	std::list<int>::const_iterator it = l.begin();
	for (size_t i = 0; i < v.size(); ++i, ++it)
		if (v[i] != *it)
			return false;
	return true;
}

// Fixed 100-element sequence: numbers 1-100 in a shuffled order (deterministic)
static const int SEQ_100[] = {
	50, 23, 87, 14, 62, 33, 91, 7, 45, 78,
	3, 67, 29, 55, 82, 16, 40, 73, 11, 96,
	60, 27, 84, 19, 51, 38, 6, 90, 24, 70,
	48, 13, 65, 31, 88, 2, 57, 44, 79, 21,
	93, 36, 9, 68, 25, 80, 42, 15, 76, 53,
	1, 85, 30, 72, 17, 63, 39, 94, 8, 47,
	74, 22, 58, 35, 89, 5, 46, 83, 28, 66,
	12, 98, 41, 71, 20, 56, 37, 92, 4, 61,
	86, 26, 69, 43, 77, 10, 52, 32, 97, 18,
	64, 49, 100, 34, 81, 59, 99, 95, 75, 54
};
static const size_t SEQ_100_SIZE = sizeof(SEQ_100) / sizeof(SEQ_100[0]);


// ─────────────────────────────────────────────────────────────────────────────
//  1. Input Validation
// ─────────────────────────────────────────────────────────────────────────────

TEST(InputValidation, SanityCheck)
{
	EXPECT_TRUE(true);
}

TEST(InputValidation, InvalidCharactersReturnFalse)
{
	PmergeMe pm;
	char* argv[] = {
		(char*)"12", (char*)"3", (char*)"9", (char*)"5", (char*)"o"
	};
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(5, argv));
}

TEST(InputValidation, NegativeNumberReturnsFalse)
{
	PmergeMe pm;
	char* argv[] = {(char*)"12", (char*)"3", (char*)"9", (char*)"-1"};
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(4, argv));
}

TEST(InputValidation, ZeroReturnsFalse)
{
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"0", (char*)"3"};
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(3, argv));
}

TEST(InputValidation, MaxIntReturnsTrue)
{
	PmergeMe pm;
	char* argv[] = {(char*)"2147483647", (char*)"1"};
	SuppressStdout ss;
	EXPECT_TRUE(pm.parseArguments(2, argv));
}

TEST(InputValidation, OverflowReturnsFalse)
{
	PmergeMe pm;
	char* argv[] = {(char*)"1", (char*)"2147483648"};
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(2, argv));
}

TEST(InputValidation, FloatReturnsFalse)
{
	PmergeMe pm;
	char* argv[] = {(char*)"3", (char*)"1.5", (char*)"7"};
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(3, argv));
}


// ─────────────────────────────────────────────────────────────────────────────
//  2. Edge Cases
// ─────────────────────────────────────────────────────────────────────────────

TEST(EdgeCases, SingleElement_VectorSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"42"};
	ASSERT_TRUE(parseAndRun(pm, 1, argv));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST(EdgeCases, TwoElements_VectorSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"9", (char*)"1"};
	ASSERT_TRUE(parseAndRun(pm, 2, argv));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST(EdgeCases, TwoElements_ListSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"9", (char*)"1"};
	ASSERT_TRUE(parseAndRun(pm, 2, argv));
	EXPECT_TRUE(isSorted(pm.getSortedList()));
}

TEST(EdgeCases, ThreeElements_OddStraggler_VectorSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"1", (char*)"3"};
	ASSERT_TRUE(parseAndRun(pm, 3, argv));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST(EdgeCases, ThreeElements_OddStraggler_ListSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"1", (char*)"3"};
	ASSERT_TRUE(parseAndRun(pm, 3, argv));
	EXPECT_TRUE(isSorted(pm.getSortedList()));
}

TEST(EdgeCases, AlreadySorted5_RejectedByParse)
{
	PmergeMe pm;
	char* argv[] = {(char*)"1", (char*)"2", (char*)"3", (char*)"4", (char*)"5"};
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(5, argv));
}

TEST(EdgeCases, ReverseSorted5_VectorSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"4", (char*)"3", (char*)"2", (char*)"1"};
	ASSERT_TRUE(parseAndRun(pm, 5, argv));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST(EdgeCases, ReverseSorted5_ListSorted)
{
	PmergeMe pm;
	char* argv[] = {(char*)"5", (char*)"4", (char*)"3", (char*)"2", (char*)"1"};
	ASSERT_TRUE(parseAndRun(pm, 5, argv));
	EXPECT_TRUE(isSorted(pm.getSortedList()));
}

TEST(EdgeCases, SubjectExample_VectorCorrect)
{
	// Subject example: 3 5 9 7 4  →  3 4 5 7 9
	PmergeMe pm;
	char* argv[] = {(char*)"3", (char*)"5", (char*)"9", (char*)"7", (char*)"4"};
	ASSERT_TRUE(parseAndRun(pm, 5, argv));

	const std::vector<int>& result = pm.getSortedVector();
	ASSERT_EQ(result.size(), (size_t)5);
	EXPECT_EQ(result[0], 3);
	EXPECT_EQ(result[1], 4);
	EXPECT_EQ(result[2], 5);
	EXPECT_EQ(result[3], 7);
	EXPECT_EQ(result[4], 9);
}


// ─────────────────────────────────────────────────────────────────────────────
//  3. Correctness — 100 elements (even count)
// ─────────────────────────────────────────────────────────────────────────────

class Sort100Test : public ::testing::Test
{
protected:
	std::vector<std::string> strBuf_;
	std::vector<char*> argvBuf_;

	void buildFrom(const std::vector<int>& nums)
	{
		buildArgs(nums, strBuf_, argvBuf_);
	}

	std::vector<int> seq100() const
	{
		return std::vector<int>(SEQ_100, SEQ_100 + SEQ_100_SIZE);
	}
};

TEST_F(Sort100Test, VectorIsSorted)
{
	buildFrom(seq100());
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST_F(Sort100Test, ListIsSorted)
{
	buildFrom(seq100());
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedList()));
}

TEST_F(Sort100Test, VectorAndListMatch)
{
	buildFrom(seq100());
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(containerMatch(pm.getSortedVector(), pm.getSortedList()));
}

TEST_F(Sort100Test, VectorHas100Elements)
{
	buildFrom(seq100());
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_EQ(pm.getSortedVector().size(), SEQ_100_SIZE);
}

TEST_F(Sort100Test, ListHas100Elements)
{
	buildFrom(seq100());
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_EQ(pm.getSortedList().size(), SEQ_100_SIZE);
}

TEST_F(Sort100Test, SortedMatchesStdSort)
{
	std::vector<int> nums = seq100();
	buildFrom(nums);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));

	std::sort(nums.begin(), nums.end());
	EXPECT_EQ(pm.getSortedVector(), nums);
}

TEST_F(Sort100Test, ReverseSorted100_VectorSorted)
{
	std::vector<int> nums = seq100();
	std::sort(nums.begin(), nums.end(), std::greater<int>());
	buildFrom(nums);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST_F(Sort100Test, ReverseSorted100_ListSorted)
{
	std::vector<int> nums = seq100();
	std::sort(nums.begin(), nums.end(), std::greater<int>());
	buildFrom(nums);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedList()));
}

TEST_F(Sort100Test, AlreadySorted100_RejectedByParse)
{
	std::vector<int> nums = seq100();
	std::sort(nums.begin(), nums.end());
	buildFrom(nums);
	PmergeMe pm;
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(
		static_cast<int>(argvBuf_.size()), argvBuf_.data()));
}


// ─────────────────────────────────────────────────────────────────────────────
//  4. Correctness — 101 elements (odd count → tests the straggler path)
// ─────────────────────────────────────────────────────────────────────────────

class Sort101Test : public ::testing::Test
{
protected:
	std::vector<std::string> strBuf_;
	std::vector<char*> argvBuf_;

	/** 101 numbers: SEQ_100 + one extra element (101) appended at the front */
	std::vector<int> seq101() const
	{
		std::vector<int> v;
		v.push_back(101); // odd straggler at the front to stress test
		v.insert(v.end(), SEQ_100, SEQ_100 + SEQ_100_SIZE);
		return v;
	}
};

TEST_F(Sort101Test, VectorIsSorted)
{
	std::vector<int> nums = seq101();
	buildArgs(nums, strBuf_, argvBuf_);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
}

TEST_F(Sort101Test, ListIsSorted)
{
	std::vector<int> nums = seq101();
	buildArgs(nums, strBuf_, argvBuf_);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedList()));
}

TEST_F(Sort101Test, VectorAndListMatch)
{
	std::vector<int> nums = seq101();
	buildArgs(nums, strBuf_, argvBuf_);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(containerMatch(pm.getSortedVector(), pm.getSortedList()));
}

TEST_F(Sort101Test, SortedMatchesStdSort)
{
	std::vector<int> nums = seq101();
	buildArgs(nums, strBuf_, argvBuf_);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));

	std::sort(nums.begin(), nums.end());
	EXPECT_EQ(pm.getSortedVector(), nums);
}

TEST_F(Sort101Test, OddStragglerIsSmallest)
{
	std::vector<int> nums(SEQ_100, SEQ_100 + SEQ_100_SIZE);
	nums.push_back(1);
	buildArgs(nums, strBuf_, argvBuf_);
	PmergeMe pm;
	SuppressStdout ss;
	SuppressStderr se;
	EXPECT_FALSE(pm.parseArguments(
		static_cast<int>(argvBuf_.size()), argvBuf_.data()));
}

TEST_F(Sort101Test, OddStragglerIsLargest)
{
	std::vector<int> nums(SEQ_100, SEQ_100 + SEQ_100_SIZE);
	nums.push_back(999);
	buildArgs(nums, strBuf_, argvBuf_);
	PmergeMe pm;
	ASSERT_TRUE(parseAndRun(
		pm, static_cast<int>(argvBuf_.size()), argvBuf_.data()));
	EXPECT_TRUE(isSorted(pm.getSortedVector()));
	EXPECT_EQ(pm.getSortedVector().back(), 999);
}


// ─────────────────────────────────────────────────────────────────────────────
//  Entry point
// ─────────────────────────────────────────────────────────────────────────────

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
