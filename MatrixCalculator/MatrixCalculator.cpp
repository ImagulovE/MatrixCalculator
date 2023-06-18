#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include "Header.h"
using namespace std;

int main(const int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    if (argc == 1) {
        cout << "Не указан входной файл." << endl;
        return 1;
    }
    if (argc == 2) {
        cout << "Не указан выходной файл." << endl;
        return 1;
    }
    ifstream file(argv[1]);
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
        file.seekg(0, ios::beg);
        string line;
        getline(file, line);
        while (counter < 200 && !line.empty()) {
            getline(file, line);
            counter++;
        }
        getline(file, operation);
    }

    ErrorCode code = isMatrixCorrect(matrix1, matrix2, operation);
    if (static_cast<int>(code) != 0) {
        file.close();
        cout << static_cast<int>(code) << endl;
        return 0;
    }

    vector<vector<double>> result = operationsOnMatrices(matrix1, matrix2, operation);
    writeResultToFile(result, argv[2]);

    file.close();
    return 0;
}

// Функция для записи результата в файл
void writeResultToFile(const vector<vector<double>>& matrix, const string& filename) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                outfile << element << " ";
            }
            outfile << endl;
        }
        outfile.close();
    }
}

// Функция для выполнения действий над матриц
vector<vector<double>> operationsOnMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation) {
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
        vector<vector<double>> result(1, vector<double>(1));
        result[0][0] = determinant;
        return result;
    }
    if (operation == "^-1")
        return matrixInverse(matrix1);
}

// Функция для сложения матриц
vector<vector<double>> matrixAddition(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int numRows = matrix1.size();
    int numCols = matrix1[0].size();

    vector<vector<double>> result(numRows, vector<double>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Функция для вычитания матриц
vector<vector<double>> matrixSubtraction(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int numRows = matrix1.size();
    int numCols = matrix1[0].size();

    vector<vector<double>> result(numRows, vector<double>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// Функция для умножения матрицы на число
vector<vector<double>> multiplicationMatrixByNumber(const vector<vector<double>>& matrix, double number) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    vector<vector<double>> result(numRows, vector<double>(numCols));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = matrix[i][j] * number;
        }
    }

    return result;
}

// Функция для умножения матриц
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int numRows1 = matrix1.size();
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();
    int numCols2 = matrix2[0].size();

    vector<vector<double>> result(numRows1, vector<double>(numCols2));

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
vector<vector<double>> matrixTranspose(const vector<vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    vector<vector<double>> result(numCols, vector<double>(numRows));

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// Функция для нахождения определителя матрицы
double matrixDeterminant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    double determinant = 0;

    // Разложение по первой строке
    for (int j = 0; j < n; j++) {
        // Вычисление алгебраического дополнения
        vector<vector<double>> minor(n - 1, vector<double>(n - 1));
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

    vector<vector<double>> cofactorMatrix(size, vector<double>(size, 0.0));

    double determinant = matrixDeterminant(matrix);

    if (determinant == 0.0) {
        cout << "Матрица вырожденная. Обратной матрицы не существует." << endl;
        exit(1);
    }

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
ErrorCode isMatrixCorrect(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation) {
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
        if (!isMatrixSquare(matrix1)) {
            return ErrorCode::MatrixIsNotSquare;
        }
    }

    return ErrorCode::NoError;
}

// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const vector<vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows > 50 || numCols > 50 || numRows == 0;
}


// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const vector<vector<double>>& matrix) {
    int expectedCount = matrix.size() * matrix[0].size();
    for (const auto& row : matrix) {
        if (row.size() != matrix[0].size()) {
            return true;
        }
    }
    return false;
}

// Функция для проверки вхождения операции в список допустимых
bool isOperationInvalid(const string& operation) {
    vector<string> validOperations = { "+", "-", "&", "*", "T", "det", "^-1" };
    for (const auto& validOp : validOperations) {
        if (operation == validOp) {
            return false;
        }
    }
    return true;
}

// Функция для проверки идентичности размерностей матриц
bool areMatricesSameSize(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int numRows1 = matrix1.size();
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();
    int numCols2 = matrix2[0].size();

    return numRows1 == numRows2 && numCols1 == numCols2;
}

// Функция для проверки возможности умножения двух матриц
bool areMatricesMultiplicable(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();

    return numCols1 == numRows2;
}

// Функция для проверки возможности умножения матрицы на число
bool abilityToMulMatrixByNumber(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    return (matrix1[0].size() > 1 || matrix1.size() > 1) && matrix2[0].size() == 1 && matrix2.size() == 1;
}

// Функция для проверки матрицы на то, является ли она квадратом
bool isMatrixSquare(const vector<vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows == numCols;
}