#include "Testing.hpp"

void MyTest::testAddition() {
	int result = 2 + 2;
	CPPUNIT_ASSERT(result == 4);
}