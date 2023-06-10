#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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