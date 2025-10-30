
#include "Menu.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#define NOMINMAX
#include <Windows.h>
using namespace std;

// ======== ЗАДАНИЕ 1 ========
// Функция addarrays() — складывает элементы двух массивов float и сохраняет в третий.
void addarrays(float* a1, float* a2, float* a3, int size) {
    for (int i = 0; i < size; i++)
        *(a3 + i) = *(a1 + i) + *(a2 + i);
}

// ======== ЗАДАНИЕ 2 ========
// Функция compstr() — аналог strcmp, возвращает -1, 0, 1.
int compstr(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        s1++; s2++;
    }
    if (*s1 == *s2) return 0;
    return (*s1) ? 1 : -1;
}

// ======== ЗАДАНИЕ 3 ========
void task3() {
    const int MAXSIZE = 10;
    const int NUMARRAYS = 10;

    int a0[MAXSIZE], a1[MAXSIZE], a2[MAXSIZE], a3[MAXSIZE], a4[MAXSIZE],
        a5[MAXSIZE], a6[MAXSIZE], a7[MAXSIZE], a8[MAXSIZE], a9[MAXSIZE];

    int* ap[NUMARRAYS] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };

    cout << "Введите 10 массивов по 10 элементов:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "\nМассив #" << j << ":\n";
        for (int k = 0; k < MAXSIZE; k++) {
            cout << "  Элемент [" << k << "]: ";
            cin >> ap[j][k];
        }
    }

    cout << "\nВывод всех массивов:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "a" << j << ": ";
        for (int k = 0; k < MAXSIZE; k++)
            cout << setw(4) << ap[j][k];
        cout << endl;
    }
}

// ======== ЗАДАНИЕ 4 ========
void task4() {
    int NUMARRAYS, MAXSIZE;

    cout << "Введите количество массивов: ";
    cin >> NUMARRAYS;

    cout << "Введите размер каждого массива: ";
    cin >> MAXSIZE;

    // Создаём массив указателей
    int** ap = new int* [NUMARRAYS];

    // Выделяем память под каждый массив
    for (int j = 0; j < NUMARRAYS; j++) {
        *(ap + j) = new int[MAXSIZE];
    }

    // Ввод значений
    cout << "\nВведите элементы для " << NUMARRAYS
        << " массивов по " << MAXSIZE << " элементов:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "\nМассив #" << j + 1 << ":\n";
        for (int k = 0; k < MAXSIZE; k++) {
            cout << "  Элемент [" << k << "]: ";
            cin >> *(*(ap + j) + k);
        }
    }

    // Вывод
    cout << "\nВывод всех массивов:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "ap[" << j << "]: ";
        for (int k = 0; k < MAXSIZE; k++)
            cout << setw(4) << *(*(ap + j) + k);
        cout << endl;
    }

    // Освобождение памяти
    for (int j = 0; j < NUMARRAYS; j++)
        delete[] * (ap + j);
    delete[] ap;
}

// ======== ЗАДАНИЕ 5 ========
struct Person {
    char* name;
    double salary;
};

// Ввод данных о сотрудниках
void inputPersons(Person* arr, int n) {
    char buffer[100];
    for (int i = 0; i < n; i++) {
        cout << "\nСотрудник #" << i + 1 << endl;
        cout << "Введите имя: ";
        cin >> ws; // пропуск пробелов
        cin.getline(buffer, 100);

        arr[i].name = new char[strlen(buffer) + 1];
        strcpy_s(arr[i].name, strlen(buffer) + 1, buffer);

        cout << "Введите зарплату: ";
        cin >> arr[i].salary;
    }
}

// Вывод данных
void printPersons(Person* arr, int n) {
    cout << "\n---------------------------------------\n";
    cout << left << setw(20) << "Имя" << setw(10) << "Зарплата" << endl;
    cout << "---------------------------------------\n";
    for (int i = 0; i < n; i++)
        cout << left << setw(20) << arr[i].name << setw(10) << arr[i].salary << endl;
}

// Сортировка — по имени (через compstr) или по зарплате
void sortPersons(Person* arr, int n, bool byName) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool swapNeeded = false;

            if (byName) {
                // используем compstr() из задания 2
                if (compstr(arr[i].name, arr[j].name) > 0)
                    swapNeeded = true;
            }
            else {
                if (arr[i].salary > arr[j].salary)
                    swapNeeded = true;
            }

            if (swapNeeded) {
                Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
    
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Menu menu;
    int choice;

    do {
        choice = menu.show();
        system("cls");

        switch (choice) {
        case 1: {
            cout << "ЗАДАНИЕ 1 — Сложение массивов (указатели)\n\n";
            int size;
            cout << "Введите размер массивов: ";
            cin >> size;

            float* a1 = new float[size];
            float* a2 = new float[size];
            float* a3 = new float[size];

            cout << "\nВведите элементы первого массива:\n";
            for (int i = 0; i < size; i++) {
                cout << "a1[" << i << "] = ";
                cin >> *(a1 + i);
            }

            cout << "\nВведите элементы второго массива:\n";
            for (int i = 0; i < size; i++) {
                cout << "a2[" << i << "] = ";
                cin >> *(a2 + i);
            }

            addarrays(a1, a2, a3, size);

            cout << "\nРезультирующий массив:\n";
            for (int i = 0; i < size; i++)
                cout << a1[i] << " + " << a2[i] << " = " << a3[i] << endl;

            delete[] a1;
            delete[] a2;
            delete[] a3;
            break;
        }
        case 2: {
            cout << "ЗАДАНИЕ 2 — Сравнение строк compstr()\n\n";
            char s1[100], s2[100];
            cout << "Введите первую строку: ";
            cin >> ws;
            cin.getline(s1, 100);
            cout << "Введите вторую строку: ";
            cin.getline(s2, 100);

            int res = compstr(s1, s2);
            cout << "\nРезультат сравнения: ";
            if (res == 0)
                cout << "строки равны.\n";
            else if (res < 0)
                cout << "\"" << s1 << "\" идёт первой по алфавиту.\n";
            else
                cout << "\"" << s2 << "\" идёт первой по алфавиту.\n";
            break;
        }
        case 3:
            cout << "ЗАДАНИЕ 3 — 10 массивов по 10 элементов (указатели)\n\n";
            task3();
            break;
        case 4:
            cout << "ЗАДАНИЕ 4 — Динамическое создание массивов (new)\n\n";
            task4();
            break;
        case 5: {
            cout << "ЗАДАНИЕ 5 — Структура Person (динамическая память, сортировка)\n\n";
            int n;
            cout << "Введите количество сотрудников: ";
            cin >> n;

            Person* people = new Person[n];
            inputPersons(people, n);

            cout << "\nСписок сотрудников до сортировки:\n";
            printPersons(people, n);

            int sortChoice;
            cout << "\nСортировать по:\n"
                << "1 — имени (используется compstr)\n"
                << "2 — зарплате\n"
                << "Ваш выбор: ";
            cin >> sortChoice;

            bool byName = (sortChoice == 1);
            sortPersons(people, n, byName);

            cout << "\nПосле сортировки:\n";
            printPersons(people, n);

            // освобождаем память
            for (int i = 0; i < n; i++)
                delete[] people[i].name;
            delete[] people;
            break;
        }
        case 0:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }

        if (choice != 0) {
            cout << "\nНажмите Enter, чтобы вернуться в меню...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("cls");
        }

    } while (choice != 0);

    return 0;
}
