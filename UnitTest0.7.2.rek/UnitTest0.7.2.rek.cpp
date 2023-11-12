#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-07.2/PR-07.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest072it
{
	TEST_CLASS(UnitTest072it)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Arrange
			const int n = 5; // або будь-яке інше значення
			int row[n] = { 5, 3, 8, 2, 7 };

			// Act
			int result = FindMinInRow(row, n);

			// Assert
			Assert::AreEqual(2, result); // Очікуємо, що мінімальний елемент у рядку - 2
		}
	};
}
