#include <vector>
#include <string>
using namespace std;

enum class ErrorCode {
    NoError, MatrixSizeOutOfRange, MissingNumber, UnknownOperation, DifferentSizesOfMatrices,
    MatrixInconsistency, InabilityToMulMatrixByNumber, MatrixIsNotSquare, NumberOfMatricesNotCorrespondOperation,
    IncorrectInputData
};

// Функция для чтения матрицы из файла
vector<vector<int>> readMatrixFromFile(ifstream& file);
// Функция для разделения строки на числа
vector<int> splitStringToInt(const string& str);
// Функция для проверки матриц на корректность
ErrorCode isMatrixCorrect(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::string operation);
// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const std::vector<std::vector<int>>& matrix);
// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const std::vector<std::vector<int>>& matrix);
// Функция для проверки вхождения операции в список допустимых
bool isOperationInvalid(const std::string& operation);
// Функция для проверки одинаковости размерностей матриц
bool areMatricesSameSize(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// Функция для проверки возможности умножения двух матриц
bool areMatricesMultiplicable(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// Функция для проверки возможности умножения матрицы на число
bool abilityToMulMatrixByNumber(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2);
// Функция для проверки матрицы на то, является ли она квадратом
bool isMatrixSquare(const std::vector<std::vector<int>>& matrix);