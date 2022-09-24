#include <iostream>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <netinet/in.h>
#include <string>
#include "functions.cpp"

using namespace CppUnit;
using namespace std;

class testuser: public CppUnit::TestFixture
{	
	CPPUNIT_TEST_SUITE(testuser);
	CPPUNIT_TEST(test_create_account);
	CPPUNIT_TEST(test_view_details);
	CPPUNIT_TEST(test_select_centre);
	CPPUNIT_TEST(test_book_slot);
	CPPUNIT_TEST(test_get_vaccinated);
	CPPUNIT_TEST_SUITE_END();
	
	public:
		void setUp(void);
		void tearDown(void);
	protected:
		void test_create_account(void);
		void test_view_details(void);
		void test_select_centre(void);
		void test_book_slot(void);
		void test_get_vaccinated(void);
	private:
		user *u1;
};

void testuser::test_create_account(void)
{
	CPPUNIT_ASSERT(0==u1->create_account());
}

void testuser::test_view_details(void)
{
	CPPUNIT_ASSERT(0==u1->view_details());
}

void testuser::test_select_centre(void)
{
	CPPUNIT_ASSERT(0==u1->select_centre());
}

void testuser::test_book_slot(void)
{
	CPPUNIT_ASSERT(0==u1->book_slot());
}

void testuser::test_get_vaccinated(void)
{
	CPPUNIT_ASSERT(0==u1->get_vaccinated());
}

void testuser::setUp(void)
{
	u1=new user();
}

void testuser::tearDown(void)
{
	delete u1;
}

CPPUNIT_TEST_SUITE_REGISTRATION(testuser);

int main(int argc,char* argv[])
{
	CPPUNIT_NS::TestResult testresult;
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults,std::cerr);
	compileroutputter.write();
	return collectedresults.wasSuccessful()?0:1;

}


