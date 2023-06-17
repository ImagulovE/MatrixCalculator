#include <vector>
#include <string>
using namespace std;

enum class ErrorCode {
    NoError, MatrixSizeOutOfRange, MissingNumber, UnknownOperation, DifferentSizesOfMatrices,
    MatrixInconsistency, InabilityToMulMatrixByNumber, MatrixIsNotSquare, NumberOfMatricesNotCorrespondOperation,
    IncorrectInputData
};

// Функция для чтения матрицы из файла
vector<vector<double>> readMatrixFromFile(ifstream& file);
// Функция для разделения строки на числа
vector<double> splitStringToInt(const string& str);
// Функция для проверки матриц на корректность
ErrorCode isMatrixCorrect(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, std::string operation);
// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const std::vector<std::vector<double>>& matrix);
// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const std::vector<std::vector<double>>& matrix);
// Функция для проверки вхождения операции в список допустимых
bool isOperationInvalid(const std::string& operation);
// Функция для проверки одинаковости размерностей матриц
bool areMatricesSameSize(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// Функция для проверки возможности умножения двух матриц
bool areMatricesMultiplicable(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// Функция для проверки возможности умножения матрицы на число
bool abilityToMulMatrixByNumber(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// Функция для проверки матрицы на то, является ли она квадратом
bool isMatrixSquare(const std::vector<std::vector<double>>& matrix);
// Функция для выполнения действий над матрицами
std::vector<std::vector<double>> operationsOnMatrices(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, std::string operation);
// Функция для сложения матриц
std::vector<std::vector<double>> matrixAddition(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// Функция для вычитания матриц
std::vector<std::vector<double>> matrixSubtraction(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// Функция для умножения матрицы на число
std::vector<std::vector<double>> multiplicationMatrixByNumber(const std::vector<std::vector<double>>& matrix, double number);
// Функция для умножения матриц
std::vector<std::vector<double>> matrixMultiplication(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
// Функция для транспонирования матрицы
std::vector<std::vector<double>> matrixTranspose(const std::vector<std::vector<double>>& matrix);
// Функция для нахождения определителя матрицы
double matrixDeterminant(const std::vector<std::vector<double>>& matrix);
// Функция для нахождения обратной матрицы
std::vector<std::vector<double>> matrixInverse(const std::vector<std::vector<double>>& matrix);
// Функция для записи результата в файл
void writeResultToFile(const vector<vector<double>>& matrix, const string& filename);