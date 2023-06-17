#include <vector>
#include <string>
using namespace std;

enum class ErrorCode {
    NoError, MatrixSizeOutOfRange, MissingNumber, UnknownOperation, DifferentSizesOfMatrices,
    MatrixInconsistency, InabilityToMulMatrixByNumber, MatrixIsNotSquare, NumberOfMatricesNotCorrespondOperation,
    IncorrectInputData
};

// ������� ��� ������ ������� �� �����
vector<vector<double>> readMatrixFromFile(ifstream& file);
// ������� ��� ���������� ������ �� �����
vector<double> splitStringToInt(const string& str);
// ������� ��� �������� ������ �� ������������
ErrorCode isMatrixCorrect(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, std::string operation);
// ������� ��� �������� ������� �������
bool isMatrixSizeInvalid(const std::vector<std::vector<double>>& matrix);
// ������� ��� �������� ����� ������� �� ����������� ���� �����
bool hasMissingNumbers(const std::vector<std::vector<double>>& matrix);
// ������� ��� �������� ��������� �������� � ������ ����������
bool isOperationInvalid(const std::string& operation);
// ������� ��� �������� ������������ ������������ ������
bool areMatricesSameSize(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// ������� ��� �������� ����������� ��������� ���� ������
bool areMatricesMultiplicable(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// ������� ��� �������� ����������� ��������� ������� �� �����
bool abilityToMulMatrixByNumber(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// ������� ��� �������� ������� �� ��, �������� �� ��� ���������
bool isMatrixSquare(const std::vector<std::vector<double>>& matrix);
// ������� ��� ���������� �������� ��� ���������
std::vector<std::vector<double>> operationsOnMatrices(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, std::string operation);
// ������� ��� �������� ������
std::vector<std::vector<double>> matrixAddition(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// ������� ��� ��������� ������
std::vector<std::vector<double>> matrixSubtraction(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// ������� ��� ��������� ������� �� �����
std::vector<std::vector<double>> multiplicationMatrixByNumber(const std::vector<std::vector<double>>& matrix, double number);
// ������� ��� ��������� ������
std::vector<std::vector<double>> matrixMultiplication(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// ������� ��� ���������������� �������
std::vector<std::vector<double>> matrixTranspose(const std::vector<std::vector<double>>& matrix);
// ������� ��� ���������� ������������ �������
double matrixDeterminant(const std::vector<std::vector<double>>& matrix);
// ������� ��� ���������� �������� �������
std::vector<std::vector<double>> matrixInverse(const std::vector<std::vector<double>>& matrix);
// ������� ��� ������ ���������� � ����
void writeResultToFile(const vector<vector<double>>& matrix, const string& filename);