#include <vector>
#include <string>
using namespace std;

enum class ErrorCode {
    NoError, MatrixSizeOutOfRange, MissingNumber, UnknownOperation, DifferentSizesOfMatrices,
    MatrixInconsistency, InabilityToMulMatrixByNumber, MatrixIsNotSquare, NumberOfMatricesNotCorrespondOperation,
    IncorrectInputData
};

// ������� ��� ������ ������� �� �����
vector<vector<int>> readMatrixFromFile(ifstream& file);
// ������� ��� ���������� ������ �� �����
vector<int> splitStringToInt(const string& str);
// ������� ��� �������� ������ �� ������������
ErrorCode isMatrixCorrect(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::string operation);
// ������� ��� �������� ������� �������
bool isMatrixSizeInvalid(const std::vector<std::vector<int>>& matrix);
// ������� ��� �������� ����� ������� �� ����������� ���� �����
bool hasMissingNumbers(const std::vector<std::vector<int>>& matrix);
// ������� ��� �������� ��������� �������� � ������ ����������
bool isOperationInvalid(const std::string& operation);
// ������� ��� �������� ������������ ������������ ������
bool areMatricesSameSize(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// ������� ��� �������� ����������� ��������� ���� ������
bool areMatricesMultiplicable(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// ������� ��� �������� ����������� ��������� ������� �� �����
bool abilityToMulMatrixByNumber(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// ������� ��� �������� ������� �� ��, �������� �� ��� ���������
bool isMatrixSquare(const std::vector<std::vector<int>>& matrix);
// ������� ��� ���������� �������� ��� ���������
std::vector<std::vector<int>> operationsOnMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::string operation);
// ������� ��� �������� ������
std::vector<std::vector<int>> matrixAddition(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// ������� ��� ��������� ������
std::vector<std::vector<int>> matrixSubtraction(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// ������� ��� ��������� ������� �� �����
std::vector<std::vector<int>> multiplicationMatrixByNumber(const std::vector<std::vector<int>>& matrix, int number);
// ������� ��� ��������� ������
std::vector<std::vector<int>> matrixMultiplication(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// ������� ��� ���������������� �������
std::vector<std::vector<int>> matrixTranspose(const std::vector<std::vector<int>>& matrix);
// ������� ��� ���������� ������������ �������
double matrixDeterminant(const std::vector<std::vector<int>>& matrix);
// ������� ��� ���������� �������� �������
std::vector<std::vector<double>> matrixInverse(const std::vector<std::vector<int>>& matrix);