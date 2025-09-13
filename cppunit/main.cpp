#include <cppunit/ui/text/TestRunner.h>
#include "Testing.hpp"

int main() {
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(MyTest::suite());
	return runner.run() ? 0 : 1;
}
