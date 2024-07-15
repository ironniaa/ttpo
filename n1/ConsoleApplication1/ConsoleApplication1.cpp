
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int neg(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int size, *arr;
   cout << "Введите размер массива: ";
   cin >> size;

    if (size <= 0) {
    cout << "Размер массива должен быть положительным числом.\n";
        return 1;
    }

    // Выделение памяти под массив
  arr = new int[size];

    // Заполнение массива случайными числами от -50 до 49
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 - 50;
    }

    // Вывод массива (для проверки)
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
   cout << endl;

    // Вычисление и вывод суммы отрицательных чисел
    int sum = neg( arr, size);
    cout << "Сумма отрицательных чисел: " << sum << endl;

    // Освобождение памяти
    delete[] arr;

    return 0;
}

