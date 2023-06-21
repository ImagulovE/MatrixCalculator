#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsplitStringToInt
{
	TEST_CLASS(TestsplitStringToInt)
	{
	public:
		
		TEST_METHOD(SampleTest)
		{
			string str = "2 5 6";
			vector<double> numVector = splitStringToInt(str);
			vector<double> expectedVector = { 2, 5, 6 };

			for (int i = 0; i < numVector.size(); i++)
			{
				Assert::AreEqual(numVector[i], expectedVector[i]);
			}
		}

		TEST_METHOD(OnlyFractionalNumbers)
		{
			string str = "2.5 7.2 9.4";
			vector<double> numVector = splitStringToInt(str);
			vector<double> expectedVector = { 2.5, 7.2, 9.4 };

			for (int i = 0; i < numVector.size(); i++)
			{
				Assert::AreEqual(numVector[i], expectedVector[i]);
			}
		}

		TEST_METHOD(IntegerAndFractionalNumbers)
		{
			string str = "2.5 7 9.4";
			vector<double> numVector = splitStringToInt(str);
			vector<double> expectedVector = { 2.5, 7, 9.4 };

			for (int i = 0; i < numVector.size(); i++)
			{
				Assert::AreEqual(numVector[i], expectedVector[i]);
			}
		}

		TEST_METHOD(MultipleSpacesBetweenNumbers)
		{
			string str = "5    9  2";
			vector<double> numVector = splitStringToInt(str);
			vector<double> expectedVector = { 5, 9, 2 };

			for (int i = 0; i < numVector.size(); i++)
			{
				Assert::AreEqual(numVector[i], expectedVector[i]);
			}
		}

		TEST_METHOD(NumbersWithInvalidCharacters)
		{
			string str = "5    a  2";
			vector<double> numVector = splitStringToInt(str);
			vector<double> expectedVector = { 5, 2 };

			for (int i = 0; i < numVector.size(); i++)
			{
				Assert::AreEqual(numVector[i], expectedVector[i]);
			}
		}
	};
}
