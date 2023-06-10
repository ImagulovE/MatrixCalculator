#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Header.h"
using namespace std;

int main() {
    ifstream file("C:\\Users\\Эльдар\\Desktop\\КиНПО\\MatrixCalculator\\input.txt");
    if (!file) {
        cout << "Неверно указан файл с входными данными. Возможно, файл не существует." << endl;
        return 1;
    }

    vector<vector<int>> matrix1, matrix2;
    string operation;

    matrix1 = readMatrixFromFile(file);
    matrix2 = readMatrixFromFile(file);
    getline(file, operation);

    if (matrix2[0].empty()) {
        file.clear();
        file.seekg(0, std::ios::beg);
        string line;
        getline(file, line);
        while (!line.empty()) {
            getline(file, line);
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
     // Проверка на размерность матриц
    if (isMatrixSizeInvalid(matrix1) || isMatrixSizeInvalid(matrix2)) {
        return ErrorCode::MatrixSizeOutOfRange;
    }

    // Проверка на то, не пропущены ли числа в матрице
    if (hasMissingNumbers(matrix1) || hasMissingNumbers(matrix2)) {
        return ErrorCode::MissingNumber;
    }

    return ErrorCode::NoError;
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

// Функция для проверки размера матрицы
bool isMatrixSizeInvalid(const std::vector<std::vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    return numRows > 50 || numCols > 50 || numRows == 0;
}