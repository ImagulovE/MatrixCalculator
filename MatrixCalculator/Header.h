#include <vector>
#include <string>
using namespace std;

/// Перечисление с кодами ошибок
enum class ErrorCode {
    /// Матрицы и операция введены правильно
    NoError, 
    /// Матрица превышает размер 50х50
    MatrixSizeOutOfRange,
    /// В матрице пропущены числа
    MissingNumber,
    /// Введена неизвестная операция
    UnknownOperation,
    /// Операция требует, чтобы матрицы были одинаковых размеров, но они разные
    DifferentSizesOfMatrices,
    /// Операция умножения требует, чтобы матрицы были согласованными, но они не согласованные
    MatrixInconsistency, 
    /// Невозможно умножить матрицу на число, так как первый множитель не матрица или второй множитель не число
    InabilityToMulMatrixByNumber, 
    /// Операция требует, чтобы матрица была квадратной, но она не квадратная
    MatrixIsNotSquare, 
    /// Количество матриц не соответствует введенной операции
    NumberOfMatricesNotCorrespondOperation,
    /// Данные не правильно введены
    IncorrectInputData
};

/*!
Считывает матрицу из файла
\param[in] file Файл с матрицей
\return Считанную матрицу
*/
vector<vector<double>> readMatrixFromFile(ifstream& file);

/*!
Разбивает строку на вектор чисел
\param[in] str Строка с числами
\return Вектор чисел
*/
vector<double> splitStringToInt(const string& str);

/*!
Проверяет матрицы на корректность и возможность выполнения над ними действия
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\param[in] operation Действие над матрицами
\return Код ошибки
*/
ErrorCode isMatrixCorrect(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation);

/*!
Проверяет размер матрицы
\param[in] matrix Матрица
\return Логическое значение, которое показывает, правильный ли размер у матрицы
*/
bool isMatrixSizeInvalid(const vector<vector<double>>& matrix);

/*!
Проверяет матрицу на пропущенные числа
\param[in] matrix Матрица
\return Логическое значение, которое показывает, не пропущены ли в матрице числа
*/
bool hasMissingNumbers(const vector<vector<double>>& matrix);

/*!
Проверяет, входит ли введенное действие над матрицами в список допустимых
\param[in] operation Действие над матрицами
\return Логическое значение, которое показывает, не входит ли введенное действие над матрицами в список допустимых
*/
bool isOperationInvalid(const string& operation);

/*!
Проверяет матрицы на идентичность их размеров
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\return Логическое значение, которое показывает, идентичны ли размеры у матриц
*/
bool areMatricesSameSize(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);

/*!
Проверяет матрицы на то, можно ли их умножить друг на друга
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\return Логическое значение, которое показывает, можно ли их умножить друг на друга
*/
bool areMatricesMultiplicable(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);

/*!
Выполняет проверку того, можно ли умножить матрицу на число
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\return Логическое значение, которое показывает, можно ли умножить матрицу на число
*/
bool abilityToMulMatrixByNumber(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);

/*!
Проверяет матрицу на то, является ли она квадратной
\param[in] matrix Матрица
\return Логическое значение, которое показывает, является ли матрица квадратной
*/
bool isMatrixSquare(const vector<vector<double>>& matrix);

/*!
Выполняет действия над матрицами
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\param[in] operation Действие над матрицами
\return Результирующую матрицу
*/
vector<vector<double>> operationsOnMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2, string operation);

/*!
Складывает две матрицы
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\return Результирующую матрицу
*/
vector<vector<double>> matrixAddition(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);

/*!
Вычитает две матрицы
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\return Результирующую матрицу
*/
vector<vector<double>> matrixSubtraction(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);

/*!
Умножает матрицу на число
\param[in] matrix1 Первая матрица
\param[in] number Число
\return Результирующую матрицу
*/
vector<vector<double>> multiplicationMatrixByNumber(const vector<vector<double>>& matrix, double number);

/*!
Умножает матрицу на другую матрицу
\param[in] matrix1 Первая матрица
\param[in] matrix2 Вторая матрица
\return Результирующую матрицу
*/
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2);

/*!
Транспонирует матрицу
\param[in] matrix Матрица
\return Результирующую матрицу
*/
vector<vector<double>> matrixTranspose(const vector<vector<double>>& matrix);

/*!
Находит определитель матрицы
\param[in] matrix Матрица
\return Определитель
*/
double matrixDeterminant(const vector<vector<double>>& matrix);

/*!
Находит обратную матрицу
\param[in] matrix Матрица
\return Результирующую матрицу
*/
vector<vector<double>> matrixInverse(const vector<vector<double>>& matrix);

/*!
Находит обратную матрицу
\param[in] matrix Матрица
\param[in] filename Файл, куда запишется матрица
*/
void writeResultToFile(const vector<vector<double>>& matrix, const string& filename);