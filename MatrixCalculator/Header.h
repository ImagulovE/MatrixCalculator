#include <vector>
#include <string>
using namespace std;

enum class ErrorCode {
    NoError, MatrixSizeOutOfRange, MissingNumber, UnknownOperation, DifferentSizesOfMatrices,
    MatrixInconsistency, InabilityToMulMatrixByNumber, MatrixIsNotSquare
};

// Функция для чтения матрицы из файла
vector<vector<int>> readMatrixFromFile(ifstream& file);
// Функция для разделения строки на числа
vector<int> splitStringToInt(const string& str);
// Функция для проверки матриц на корректность
ErrorCode isMatrixCorrect(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::string operation);
// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const std::vector<std::vector<int>>& matrix);
// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const std::vector<std::vector<int>>& matrix);