#include "pch.h"
#include "CppUnitTest.h"
#include "../12.3 rec/12.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Elem* test;
			test = new Elem;
			test->info = -5;
			test->prev = NULL;
			test->next = new Elem;
			test->next->info = 0;
			test->next->prev = test;
			test->next->next = new Elem;
			test->next->next->info = -2;
			test->next->next->prev = test->next;
			test->next->next->next = NULL;

			Assert::AreEqual(2, count(test, 0));
		}
	};
}
