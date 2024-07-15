#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm> // для std::min
using namespace std;
// Функция для вычисления суммы элементов на главной диагонали матрицы
int calc(int *matrix[], int rows, int cols) {
    int disize = min(rows, cols); // Размер диагонали - меньшее из размерностей
    int sum = 0;

    for (int i = 0; i < disize; ++i) {
        sum += matrix[i][i];
    }

    return sum;
}




int main() {
    setlocale(LC_ALL, "Russian");

    int rows, cols;
    cout << "Введите количество строк матрицы: ";
    cin >> rows;
    cout << "Введите количество столбцов матрицы: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Размеры матрицы должны быть положительными числами.\n";
        return 1;
    }

    // Выделение памяти под матрицу
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Заполнение матрицы случайными числами
   srand(time(nullptr));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Вывод матрицы (для проверки)
   cout << "Сгенерированная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Вычисление и вывод суммы элементов на главной диагонали
    int diagonalSum = calc(matrix, rows, cols);
    std::cout << "Сумма элементов на главной диагонали: " << diagonalSum << std::endl;

    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
