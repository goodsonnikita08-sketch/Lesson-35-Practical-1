#include <iostream>
#include <fstream>
#include <Windows.h>
#include "dop.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int choice;
    std::cout << "Выберите действие:\n";
    std::cout << "1 - Создать случайную матрицу и вывести в консоль\n";
    std::cout << "2 - Ввести матрицу с консоли\n";
    std::cout << "3 - Сохранить матрицу в файл (matrix.txt)\n";
    std::cout << "4 - Загрузить матрицу из файла (matrix.txt)\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        int r, c;
        std::cout << "Введите количество строк и столбцов: ";
        std::cin >> r >> c;

        Matrix m1(r, c);
        std::cout << "\nСгенерированная матрица:\n";
        std::cout << m1;
        break;
    }
    case 2: {
        Matrix m2;
        std::cout << "\nВведите размеры (строки столбцы), а затем сами элементы:\n";
        std::cout << "(например: 2 2\n1 2\n3 4)\n";
        std::cin >> m2;

        std::cout << "\nВы ввели матрицу:\n";
        std::cout << m2;
        break;
    }
    case 3: {
        Matrix m3(3, 4);
        std::cout << "\nМатрица для сохранения:\n";
        std::cout << m3;

        std::ofstream fileOut("matrix.txt");
        if (fileOut.is_open()) {
            fileOut << m3;
            fileOut.close();
            std::cout << "Матрица успешно сохранена в файл matrix.txt!\n";
        }
        else {
            std::cout << "Ошибка открытия файла для записи!\n";
        }
        break;
    }
    case 4: {
        Matrix m4;
        std::ifstream fileIn("matrix.txt");
        if (fileIn.is_open()) {
            fileIn >> m4;
            fileIn.close();

            std::cout << "\nМатрица успешно загружена из файла! Вот она:\n";
            std::cout << m4;
        }
        else {
            std::cout << "Ошибка! Сначала создайте файл (выберите пункт 3).\n";
        }
        break;
    }
    default:
        std::cout << "Неверный выбор!\n";
        break;
    }

    return 0;
}