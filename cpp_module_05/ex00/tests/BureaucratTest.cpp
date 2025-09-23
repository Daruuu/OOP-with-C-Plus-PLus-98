#include <cppunit/extensions/HelperMacros.h>
#include "../Bureaucrat.hpp"

class BureaucratTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(BureaucratTest);

	CPPUNIT_TEST(testValidConstructor);
	CPPUNIT_TEST(testInvalidConstructorHigh);
	CPPUNIT_TEST(testInvalidConstructorLow);
	CPPUNIT_TEST(testIncrementValid);
	CPPUNIT_TEST(testIncrementTooHigh);
	CPPUNIT_TEST(testDecrementTooLow);

	CPPUNIT_TEST_SUITE_END();

public:

	void	testValidConstructor()
	{
		Bureaucrat b ("Alice", 24);
		CPPUNIT_ASSERT_EQUAL(std::string("Allice"), b.getName());
		CPPUNIT_ASSERT_EQUAL(24, b.getGrade());
	}

};