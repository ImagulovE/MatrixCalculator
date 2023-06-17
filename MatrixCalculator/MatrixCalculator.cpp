#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include "Header.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file("input.txt");
    if (!file) {
        cout << "Неверно указан файл с входными данными. Возможно, файл не существует." << endl;
        return 1;
    }

    vector<vector<double>> matrix1, matrix2;
    string operation;
    int counter = 0;

    matrix1 = readMatrixFromFile(file);
    matrix2 = readMatrixFromFile(file);
    getline(file, operation);

    if (matrix2.empty() || matrix2[0].empty()) {
        file.clear();
        file.seekg(0, std::ios::beg);
        string line;
        getline(file, line);
        while (counter < 200 && !line.empty()) {
            getline(file, line);
            counter++;
        }
        getline(file, operation);
    }
 
    // Вывод матриц и действия для проверки правильности считывания данных
    cout << "Matrix 1:" << endl;
    for (const auto& row : matrix1) {
        for (const auto& num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }

    cout << "Matrix 2:" << endl;
    for (const auto& row : matrix2) {
        for (const auto& num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }

    cout << "Operation: " << operation << endl;

    ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
    cout << static_cast<int>(code) << endl;

    if (static_cast<int>(code) != 0) {
        file.close();
        return 0;
    }

    vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);

    cout << "Result:" << endl;
    for (const auto& row : result) {
        for (const auto& num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }


    file.close();
    return 0;
}

// Функция для выполнения действий над матрицами
std::vector<std::vector<double>> operationsOnMatrices(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, std::string operation) {
    if (operation == "+")
        return matrixAddition(matrix1, matrix2);
    if (operation == "-")
        return matrixSubtraction(matrix1, matrix2);
    if (operation == "&")
        return multiplicationMatrixByNumber(matrix1, matrix2[0][0]);
    if (operation == "*")
        return matrixMultiplication(matrix1, matrix2);
    if (operation == "T")
        return matrixTranspose(matrix1);
    if (operation == "det") {
        double determinant = matrixDeterminant(matrix1);
        std::vector<std::vector<double>> result(1, std::vector<double>(1));
        result[0][0] = determinant;
        return result;
    }
    if (operation == "^-1")
        return matrixInverse(matrix1);
    
    return matrix1;
}

// Функция для сложения матриц
std::vector<std::vector<double>> matrixAddition(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int numRows = matrix1.size();
    int numCols = matrix1[0].size();

    std::vector<std::vector<double>> result(numRows, std::vector<double>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Функция для вычитания матриц
std::vector<std::vector<double>> matrixSubtraction(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int numRows = matrix1.size();
    int numCols = matrix1[0].size();

    std::vector<std::vector<double>> result(numRows, std::vector<double>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// Функция для умножения матрицы на число
std::vector<std::vector<double>> multiplicationMatrixByNumber(const std::vector<std::vector<double>>& matrix, double number) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    std::vector<std::vector<double>> result(numRows, std::vector<double>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix[i][j] * number;
        }
    }

    return result;
}

// Функция для умножения матриц
std::vector<std::vector<double>> matrixMultiplication(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int numRows1 = matrix1.size();
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();
    int numCols2 = matrix2[0].size();

    std::vector<std::vector<double>> result(numRows1, std::vector<double>(numCols2));

    for (int i = 0; i < numRows1; i++) {
        for (int j = 0; j < numCols2; j++) {
            double sum = 0;
            for (int k = 0; k < numCols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

// Функция для транспонирования матрицы
std::vector<std::vector<double>> matrixTranspose(const std::vector<std::vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    std::vector<std::vector<double>> result(numCols, std::vector<double>(numRows));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// Функция для нахождения определителя матрицы
double matrixDeterminant(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();

    // Базовый случай: матрица 1x1
    if (n == 1) {
        return matrix[0][0];
    }

    double determinant = 0;

    // Разложение по первой строке
    for (int j = 0; j < n; j++) {
        // Вычисление алгебраического дополнения
        std::vector<std::vector<double>> minor(n - 1, std::vector<double>(n - 1));
        for (int i = 1; i < n; i++) {
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l != j) {
                    minor[i - 1][k] = matrix[i][l];
                    k++;
                }
            }
        }

        // Рекурсивно вычисляем определитель минора
        double minorDeterminant = matrixDeterminant(minor);

        // Вычисляем алгебраическое дополнение
        int sign = (j % 2 == 0) ? 1 : -1;

        // Обновляем определитель
        determinant += sign * matrix[0][j] * minorDeterminant;
    }

    return determinant;
}

// Функция для нахождения обратной матрицы
vector<vector<double>> matrixInverse(const vector<vector<double>>& matrix) {
    int size = matrix.size();

    double determinant = matrixDeterminant(matrix);

    if (determinant == 0.0) {
        cout << "Матрица вырожденная. Обратной матрицы не существует." << endl;
        exit(1);
    }

    vector<vector<double>> cofactorMatrix(size, vector<double>(size, 0.0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            vector<vector<double>> minor(size - 1, vector<double>(size - 1, 0.0));
            int row = 0;
            for (int k = 0; k < size; k++) {
                if (k != i) {
                    int col = 0;
                    for (int l = 0; l < size; l++) {
                        if (l != j) {
                            minor[row][col] = matrix[k][l];
                            col++;
                        }
                    }
                    row++;
                }
            }
            cofactorMatrix[i][j] = pow(-1, i + j) * matrixDeterminant(minor);
        }
    }

    vector<vector<double>> inverseMatrix(size, vector<double>(size, 0.0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverseMatrix[i][j] = cofactorMatrix[j][i] / determinant;
        }
    }

    return inverseMatrix;
}

// Функция для чтения матрицы из файла
vector<vector<double>> readMatrixFromFile(ifstream& file) {
    vector<vector<double>> matrix;
    string line;
    while (getline(file, line) && !line.empty()) {
        vector<double> row = splitStringToInt(line);
        matrix.push_back(row);
    }
    return matrix;
}

// Функция для разделения строки на числа
vector<double> splitStringToInt(const string& str) {
    vector<double> row;
    stringstream ss(str);
    double num;
    while (ss >> num) {
        row.push_back(num);
    }
    return row;
}

// Функция для проверки матриц на корректность
ErrorCode isMatrixCorrect(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2, std::string operation) {
    // Проверка на то, введена ли хотя бы одна матрица и операция
    if (matrix1.empty() || operation.empty()) {
        return ErrorCode::IncorrectInputData;
    }

    // Проверка на количество матриц во входных данных
    if (operation == "T" || operation == "det" || operation == "^-1") {
        if (!matrix2[0].empty()) {
            return ErrorCode::NumberOfMatricesNotCorrespondOperation;
        }
    }

     // Проверка на размерность матриц
    if (isMatrixSizeInvalid(matrix1) || isMatrixSizeInvalid(matrix2)) {
        return ErrorCode::MatrixSizeOutOfRange;
    }

    // Проверка на то, не пропущены ли числа в матрице
    if (hasMissingNumbers(matrix1) || hasMissingNumbers(matrix2)) {
        return ErrorCode::MissingNumber;
    }

    // Проверка на то, существует ли введенная операция
    if (isOperationInvalid(operation)) {
        return ErrorCode::UnknownOperation;
    }

    // Проверка на идентичность размеров матриц
    if (operation == "+" || operation == "-") {
        if (!areMatricesSameSize(matrix1, matrix2)) {
            return ErrorCode::DifferentSizesOfMatrices;
        }
    }

    // Проверка на согласованность матриц
    if (operation == "*") {
        if (!areMatricesMultiplicable(matrix1, matrix2)) {
            return ErrorCode::MatrixInconsistency;
        }
    }

    // Проверка на возможность умножения матрицы на число
    if (operation == "&") {
        if (!abilityToMulMatrixByNumber(matrix1, matrix2)) {
            return ErrorCode::InabilityToMulMatrixByNumber;
        }
    }

    // Проверка на квадратность матрицы
    if (operation == "det" || operation == "^-1") {
        if (!matrix2[0].empty()) {
            return ErrorCode::NumberOfMatricesNotCorrespondOperation;
        }
        if (!isMatrixSquare(matrix1)) {
            return ErrorCode::MatrixIsNotSquare;
        }
    }

    return ErrorCode::NoError;
}

// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const std::vector<std::vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows > 50 || numCols > 50 || numRows == 0;
}


// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const std::vector<std::vector<double>>& matrix) {
    int expectedCount = matrix.size() * matrix[0].size();
    for (const auto& row : matrix) {
        if (row.size() != matrix[0].size()) {
            return true;
        }
    }
    return false;
}

// Функция для проверки вхождения операции в список допустимых
bool isOperationInvalid(const std::string& operation) {
    std::vector<std::string> validOperations = { "+", "-", "&", "*", "T", "det", "^-1" };
    for (const auto& validOp : validOperations) {
        if (operation == validOp) {
            return false;
        }
    }
    return true;
}

// Функция для проверки идентичности размерностей матриц
bool areMatricesSameSize(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int numRows1 = matrix1.size();
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();
    int numCols2 = matrix2[0].size();

    return numRows1 == numRows2 && numCols1 == numCols2;
}

// Функция для проверки возможности умножения двух матриц
bool areMatricesMultiplicable(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();

    return numCols1 == numRows2;
}

// Функция для проверки возможности умножения матрицы на число
bool abilityToMulMatrixByNumber(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    return (matrix1[0].size() > 1 || matrix1.size() > 1) && matrix2[0].size() == 1 && matrix2.size() == 1;
}

// Функция для проверки матрицы на то, является ли она квадратом
bool isMatrixSquare(const std::vector<std::vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows == numCols;
}