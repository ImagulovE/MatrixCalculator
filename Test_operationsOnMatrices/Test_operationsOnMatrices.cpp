#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestoperationsOnMatrices
{
	TEST_CLASS(TestoperationsOnMatrices)
	{
	public:
		
		TEST_METHOD(SampleTest)
		{
			vector<vector<double>> matrix1 = { {1, 2, 3},
											   {4, 5, 6},
											   {7, 8, 9} };
			vector<vector<double>> matrix2 = { {9, 8, 7},
											   {6, 5, 4},
											   {3, 2, 1} };
			string operation = "+";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {10, 10, 10},
													  {10, 10, 10},
													  {10, 10, 10} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}

		TEST_METHOD(MatrixSubtraction)
		{
			vector<vector<double>> matrix1 = { {1, 2, 3},
											   {4, 5, 6},
											   {7, 8, 9} };
			vector<vector<double>> matrix2 = { {9, 8, 7},
											   {6, 5, 4},
											   {3, 2, 1} };
			string operation = "-";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {-8, -6, -4},
													  {-2, 0, 2},
													  {4, 6, 8} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}

		TEST_METHOD(MultiplicationMatrixByNumber)
		{
			vector<vector<double>> matrix1 = { {1, 2, 3},
											   {4, 5, 6},
											   {7, 8, 9} };
			vector<vector<double>> matrix2 = { {10} };
			string operation = "&";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {10, 20, 30},
													  {40, 50, 60},
													  {70, 80, 90} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}

		TEST_METHOD(MatrixMultiplication)
		{
			vector<vector<double>> matrix1 = { {1, 2, 3},
											   {2, 3, 4},
											   {3, 4, 5} };
			vector<vector<double>> matrix2 = { {1, 2, 3},
											   {4, 5, 6},
											   {7, 8, 9} };
			string operation = "*";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {30, 36, 42},
													  {42, 51, 60},
													  {54, 66, 78} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}

		TEST_METHOD(TransposeMatrix)
		{
			vector<vector<double>> matrix1 = { {1, 2, 3},
											   {4, 5, 6},
											   {7, 8, 9} };
			vector<vector<double>> matrix2 = { };
			string operation = "T";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {1, 4, 7},
													  {2, 5, 8},
													  {3, 6, 9} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}

		TEST_METHOD(MatrixDeterminant)
		{
			vector<vector<double>> matrix1 = { {2, 6, 3},
											   {4, 8, 2},
											   {9, 4, 7} };
			vector<vector<double>> matrix2 = { };
			string operation = "det";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {-132} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}

		TEST_METHOD(InverseMatrix)
		{
			vector<vector<double>> matrix1 = { {2, 6, 3},
											   {4, 8, 2},
											   {9, 4, 7} };
			vector<vector<double>> matrix2 = { };
			string operation = "^-1";

			vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
			vector<vector<double>> expectedResult = { {-0.36, 0.23, 0.09},
													  {0.08, 0.1, -0.06},
													  {0.42, -0.35, 0.06} };

			for (int i = 0; i < result[0].size(); i++)
			{
				for (int j = 0; j < result.size(); j++)
				{
					Assert::AreEqual(result[i][j], expectedResult[i][j]);
				}
			}
		}
	};
}
