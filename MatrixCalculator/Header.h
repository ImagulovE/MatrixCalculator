#include <vector>
#include <string>
using namespace std;

enum class ErrorCode {
    NoError, MatrixSizeOutOfRange, MissingNumber, UnknownOperation, DifferentSizesOfMatrices,
    MatrixInconsistency, InabilityToMulMatrixByNumber, MatrixIsNotSquare
};

// ������� ��� ������ ������� �� �����
vector<vector<int>> readMatrixFromFile(ifstream& file);
// ������� ��� ���������� ������ �� �����
vector<int> splitStringToInt(const string& str);
// ������� ��� �������� ������ �� ������������
ErrorCode isMatrixCorrect(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::string operation);
// ������� ��� �������� ����� ������� �� ����������� ���� �����
bool hasMissingNumbers(const std::vector<std::vector<int>>& matrix);
// ������� ��� �������� ������� �������
bool isMatrixSizeInvalid(const std::vector<std::vector<int>>& matrix);