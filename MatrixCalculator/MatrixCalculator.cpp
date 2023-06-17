#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Header.h"
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Неверно указан файл с входными данными. Возможно, файл не существует." << endl;
        return 1;
    }

    vector<vector<int>> matrix1, matrix2;
    string operation;
    int counter = 0;

    matrix1 = readMatrixFromFile(file);
    matrix2 = readMatrixFromFile(file);
    getline(file, operation);

    if (matrix2.empty()) {
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
    cout << static_cast<int>(code);

    if (static_cast<int>(code) != 0) {
        file.close();
        return 1;
    }

    file.close();
    return 0;
}

// Функция для чтения матрицы из файла
vector<vector<int>> readMatrixFromFile(ifstream& file) {
    vector<vector<int>> matrix;
    string line;
    while (getline(file, line) && !line.empty()) {
        vector<int> row = splitStringToInt(line);
        matrix.push_back(row);
    }
    return matrix;
}

// Функция для разделения строки на числа
vector<int> splitStringToInt(const string& str) {
    vector<int> row;
    stringstream ss(str);
    int num;
    while (ss >> num) {
        row.push_back(num);
    }
    return row;
}

// Функция для проверки матриц на корректность
ErrorCode isMatrixCorrect(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::string operation) {
    // Проверка на то, введена ли хотя бы одна матрица и операция
    if (matrix1.empty() || operation.empty()) {
        return ErrorCode::IncorrectInputData;
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
bool isMatrixSizeInvalid(const std::vector<std::vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows > 50 || numCols > 50 || numRows == 0;
}


// Функция для проверки строк матрицы на присутствие всех чисел
bool hasMissingNumbers(const std::vector<std::vector<int>>& matrix) {
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
bool areMatricesSameSize(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int numRows1 = matrix1.size();
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();
    int numCols2 = matrix2[0].size();

    return numRows1 == numRows2 && numCols1 == numCols2;
}

// Функция для проверки возможности умножения двух матриц
bool areMatricesMultiplicable(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int numCols1 = matrix1[0].size();
    int numRows2 = matrix2.size();

    return numCols1 == numRows2;
}

// Функция для проверки возможности умножения матрицы на число
bool abilityToMulMatrixByNumber(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    return (matrix1[0].size() > 1 || matrix1.size() > 1) && matrix2[0].size() == 1;
}

// Функция для проверки матрицы на то, является ли она квадратом
bool isMatrixSquare(const std::vector<std::vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows == numCols;
}