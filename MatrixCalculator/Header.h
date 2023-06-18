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
ErrorCode isMatrixCorrect(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation);
// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const vector<vector<double>>& matrix);
// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const vector<vector<double>>& matrix);
// Функция для проверки вхождения операции в список допустимых
bool isOperationInvalid(const string& operation);
// Функция для проверки одинаковости размерностей матриц
bool areMatricesSameSize(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// Функция для проверки возможности умножения двух матриц
bool areMatricesMultiplicable(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// Функция для проверки возможности умножения матрицы на число
bool abilityToMulMatrixByNumber(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// Функция для проверки матрицы на то, является ли она квадратом
bool isMatrixSquare(const vector<vector<double>>& matrix);
// Функция для выполнения действий над матрицами
vector<vector<double>> operationsOnMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation);
// Функция для сложения матриц
vector<vector<double>> matrixAddition(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// Функция для вычитания матриц
vector<vector<double>> matrixSubtraction(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// Функция для умножения матрицы на число
vector<vector<double>> multiplicationMatrixByNumber(const vector<vector<double>>& matrix, double number);
// Функция для умножения матриц
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);
// Функция для транспонирования матрицы
vector<vector<double>> matrixTranspose(const vector<vector<double>>& matrix);
// Функция для нахождения определителя матрицы
double matrixDeterminant(const vector<vector<double>>& matrix);
// Функция для нахождения обратной матрицы
vector<vector<double>> matrixInverse(const vector<vector<double>>& matrix);
// Функция для записи результата в файл
void writeResultToFile(const vector<vector<double>>& matrix, const string& filename);