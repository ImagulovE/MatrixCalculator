#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestisMatrixCorrect
{
	TEST_CLASS(TestisMatrixCorrect)
	{
	public:
		
		TEST_METHOD(SampleTest)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {2, 5, 3},
											   {1, 7, 1},
											   {8, 5, 4} };
			string operation = "+";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::NoError));
		}

		TEST_METHOD(MissingMatrix)
		{
			vector<vector<double>> matrix1;
			vector<vector<double>> matrix2;
			string operation = "det";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::IncorrectInputData));
		}

		TEST_METHOD(MissingOperation)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2;
			string operation;

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::IncorrectInputData));
		}

		TEST_METHOD(MatrixSizeOutOfRange)
		{
			vector<vector<double>> matrix1 = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, };
			vector<vector<double>> matrix2 = { {} };
			string operation = "det";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::MatrixSizeOutOfRange));
		}

		TEST_METHOD(MissingNumber)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7,    2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {} };
			string operation = "det";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::MissingNumber));
		}

		TEST_METHOD(TwoMatricesGivenInsteadOne)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {2, 5, 3},
											   {1, 7, 1},
											   {8, 5, 4} };
			string operation = "T";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::NumberOfMatricesNotCorrespondOperation));
		}

		TEST_METHOD(UnknownOperationGiven)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {2, 5, 3},
											   {1, 7, 1},
											   {8, 5, 4} };
			string operation = "=";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::UnknownOperation));
		}

		TEST_METHOD(MatrixSizesNotMatch)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {2, 5},
											   {1, 7},
											   {8, 5} };
			string operation = "+";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::DifferentSizesOfMatrices));
		}

		TEST_METHOD(MatricesAreInconsistent)
		{
			vector<vector<double>> matrix1 = { {1, 7},
											   {7, 4},
											   {9, 5} };
			vector<vector<double>> matrix2 = { {2, 5},
											   {1, 7},
											   {8, 5} };
			string operation = "*";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::MatrixInconsistency));
		}

		TEST_METHOD(SecondMultiplierShouldBeNumber)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {2, 5, 3},
											   {1, 7, 1},
											   {8, 5, 4} };
			string operation = "&";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::InabilityToMulMatrixByNumber));
		}

		TEST_METHOD(FirstMultiplierShouldBeMatrix)
		{
			vector<vector<double>> matrix1 = { {4} };
			vector<vector<double>> matrix2 = { {2, 5, 3},
											   {1, 7, 1},
											   {8, 5, 4} };
			string operation = "&";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::InabilityToMulMatrixByNumber));
		}

		TEST_METHOD(MatrixIsNotSquare)
		{
			vector<vector<double>> matrix1 = { {1, 7},
											   {7, 4},
											   {9, 5} };
			vector<vector<double>> matrix2 = { {} };
			string operation = "^-1";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::MatrixIsNotSquare));
		}

		TEST_METHOD(NoErrorTest)
		{
			vector<vector<double>> matrix1 = { {1, 7, 3},
											   {7, 4, 2},
											   {9, 5, 4} };
			vector<vector<double>> matrix2 = { {2, 5, 3},
											   {1, 7, 1},
											   {8, 5, 4} };
			string operation = "-";

			ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
			Assert::AreEqual(static_cast<int>(code), static_cast<int>(ErrorCode::NoError));
		}
	};
}
