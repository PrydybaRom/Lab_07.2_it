#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            srand((unsigned)time(NULL));
            int Low = 0;
            int High = 10;
            int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            Create(a, n, Low, High);
            int maxElement, maxRow, maxCol;

            FindMaxAboveDiagonal(a, n, maxElement, maxRow, maxCol);

            Assert::AreEqual(maxElement, 9);
		}
	};
}
