#ifndef STARTING_WITH_CPP_TESTING_HPP
#define STARTING_WITH_CPP_TESTING_HPP

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class MyTest : public CppUnit::TestCase {
	CPPUNIT_TEST_SUITE(MyTest);
	CPPUNIT_TEST(testAddition);
	CPPUNIT_TEST_SUITE_END();

public:
	void testAddition();
};

#endif //STARTING_WITH_CPP_TESTING_HPP