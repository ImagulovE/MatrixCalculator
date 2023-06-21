# MatrixCalculator
Программа предназначена для осуществления операций над матрицами.
Программа может выполнять:
- Сложение матриц;
- Вычитание матриц;
- Умножение матриц;
- Умножение матрицы на число;
- Транспонирование матрицы;
- Нахождение определителя матрицы;
- Нахождение обратной матрицы.

## Работа с программой
### _**Шаг первый**_

Создать новую папку и перенести туда программу MatrixCalculator.exe

### _**Шаг второй**_

Создать входной файл input.txt, в котором необходимо написать матрицы (или матрицу, в зависимости от выполняемого действия) и действие, которое будет выполняться над ними.
Например:  

1 2 3  
4 5 6  
7 8 9  

9 8 7  
6 5 4  
3 2 1  

\+

### _**Шаг третий - Запуск**_

Открыть  _Меню "Пуск" > Команданая строка (или cmd)  **ИЛИ**  WIN+R > cmd > Enter_. Далее, необходимо ввести следющее:  _**C:/.../MatrixCalculator.exe input.txt ./output.txt**_, где

-   _C:/..._  - путь до программы;
-   _input.txt_  - файл с входными данными (создается пользователем в папке с программой);
-   _./output.txt_  - файл с результатами работы программы (создаётся программой или перезаписывается в папке с программой).
## Возможные ошибки
-   _**NoError– код «0»**_: нет ошибки.
-   _**MatrixSizeOutOfRange– код «1»**_: размер матрицы вне разрешенного диапазона.
-   _**MissingNumber– код «2»**_: пропущено число в матрице.
-   _**UnknownOperation– код «3»**_: неизвестная операция.
-   _**DifferentSizesOfMatrices– код «4»**_: размерности матриц не совпадают.
-   _**MatrixInconsistency– код «5»**_: матрицы не согласованны.
-   _**InabilityToMulMatrixByNumber– код «6»**_: невозможность умножения матрицы на число.
-   _**MatrixIsNotSquare– код «7»**_: матрица не квадратная.
-  _**NumberOfMatricesNotCorrespondOperation– код «8»**_: количество матриц не соответствует указанному действию.
-  _**IncorrectInputData– код «9»**_: неправильно записаны входные данные.
