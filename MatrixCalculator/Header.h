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