#include "Menu.h"
#include <iostream>
using namespace std;

int Menu::show() {
    cout << "=================================\n";
    cout << "         МЕНЮ ЛАБОРАТОРНОЙ 7     \n";
    cout << "=================================\n";
    cout << "1. Сложение массивов (addarrays)\n";
    cout << "2. Сравнение строк (compstr)\n";
    cout << "3. 10 массивов по 10 элементов\n";
    cout << "4. Динамическое создание массивов\n";
    cout << "5. Структура Person + сортировка\n";
    cout << "0. Выход\n";
    cout << "---------------------------------\n";
    cout << "Введите номер задания: ";

    int choice;
    cin >> choice;
    return choice;
}
