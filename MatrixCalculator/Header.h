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
ErrorCode isMatrixCorrect(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation);
// ������� ��� �������� ������� �������
bool isMatrixSizeInvalid(const vector<vector<double>>& matrix);
// ������� ��� �������� ����� ������� �� ����������� ���� �����
bool hasMissingNumbers(const vector<vector<double>>& matrix);
// ������� ��� �������� ��������� �������� � ������ ����������
bool isOperationInvalid(const string& operation);
// ������� ��� �������� ������������ ������������ ������
bool areMatricesSameSize(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// ������� ��� �������� ����������� ��������� ���� ������
bool areMatricesMultiplicable(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// ������� ��� �������� ����������� ��������� ������� �� �����
bool abilityToMulMatrixByNumber(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// ������� ��� �������� ������� �� ��, �������� �� ��� ���������
bool isMatrixSquare(const vector<vector<double>>& matrix);
// ������� ��� ���������� �������� ��� ���������
vector<vector<double>> operationsOnMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation);
// ������� ��� �������� ������
vector<vector<double>> matrixAddition(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// ������� ��� ��������� ������
vector<vector<double>> matrixSubtraction(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// ������� ��� ��������� ������� �� �����
vector<vector<double>> multiplicationMatrixByNumber(const vector<vector<double>>& matrix, double number);
// ������� ��� ��������� ������
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// ������� ��� ���������������� �������
vector<vector<double>> matrixTranspose(const vector<vector<double>>& matrix);
// ������� ��� ���������� ������������ �������
double matrixDeterminant(const vector<vector<double>>& matrix);
// ������� ��� ���������� �������� �������
vector<vector<double>> matrixInverse(const vector<vector<double>>& matrix);
// ������� ��� ������ ���������� � ����
void writeResultToFile(const vector<vector<double>>& matrix, const string& filename);