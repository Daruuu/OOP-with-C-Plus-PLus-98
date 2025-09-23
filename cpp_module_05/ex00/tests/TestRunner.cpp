#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

// This file provides the main function that runs all the registered test suites.
// In our case, it will execute the BureaucratTest defined in BureaucratTest.cpp.

int main() {
	// The TextUi::TestRunner is a simple test runner that prints results to the console.
	CppUnit::TextUi::TestRunner runner;

	// The TestFactoryRegistry keeps track of all registered test suites.
	// By default, it will collect every suite registered with CPPUNIT_TEST_SUITE_REGISTRATION.
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

	// Add all tests from the registry to the runner.
	runner.addTest(registry.makeTest());

	// Run the tests.
	// Returns true if all tests pass, false otherwise.
	// We return 0 for success and 1 for failure, as is standard in Unix-like systems.
	return runner.run() ? 0 : 1;
}
