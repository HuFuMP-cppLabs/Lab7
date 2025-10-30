
#include "Menu.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#define NOMINMAX
#include <Windows.h>
using namespace std;

// ======== ������� 1 ========
// ������� addarrays() � ���������� �������� ���� �������� float � ��������� � ������.
void addarrays(float* a1, float* a2, float* a3, int size) {
    for (int i = 0; i < size; i++)
        *(a3 + i) = *(a1 + i) + *(a2 + i);
}

// ======== ������� 2 ========
// ������� compstr() � ������ strcmp, ���������� -1, 0, 1.
int compstr(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        s1++; s2++;
    }
    if (*s1 == *s2) return 0;
    return (*s1) ? 1 : -1;
}

// ======== ������� 3 ========
void task3() {
    const int MAXSIZE = 10;
    const int NUMARRAYS = 10;

    int a0[MAXSIZE], a1[MAXSIZE], a2[MAXSIZE], a3[MAXSIZE], a4[MAXSIZE],
        a5[MAXSIZE], a6[MAXSIZE], a7[MAXSIZE], a8[MAXSIZE], a9[MAXSIZE];

    int* ap[NUMARRAYS] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };

    cout << "������� 10 �������� �� 10 ���������:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "\n������ #" << j << ":\n";
        for (int k = 0; k < MAXSIZE; k++) {
            cout << "  ������� [" << k << "]: ";
            cin >> ap[j][k];
        }
    }

    cout << "\n����� ���� ��������:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "a" << j << ": ";
        for (int k = 0; k < MAXSIZE; k++)
            cout << setw(4) << ap[j][k];
        cout << endl;
    }
}

// ======== ������� 4 ========
void task4() {
    int NUMARRAYS, MAXSIZE;

    cout << "������� ���������� ��������: ";
    cin >> NUMARRAYS;

    cout << "������� ������ ������� �������: ";
    cin >> MAXSIZE;

    // ������ ������ ����������
    int** ap = new int* [NUMARRAYS];

    // �������� ������ ��� ������ ������
    for (int j = 0; j < NUMARRAYS; j++) {
        *(ap + j) = new int[MAXSIZE];
    }

    // ���� ��������
    cout << "\n������� �������� ��� " << NUMARRAYS
        << " �������� �� " << MAXSIZE << " ���������:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "\n������ #" << j + 1 << ":\n";
        for (int k = 0; k < MAXSIZE; k++) {
            cout << "  ������� [" << k << "]: ";
            cin >> *(*(ap + j) + k);
        }
    }

    // �����
    cout << "\n����� ���� ��������:\n";
    for (int j = 0; j < NUMARRAYS; j++) {
        cout << "ap[" << j << "]: ";
        for (int k = 0; k < MAXSIZE; k++)
            cout << setw(4) << *(*(ap + j) + k);
        cout << endl;
    }

    // ������������ ������
    for (int j = 0; j < NUMARRAYS; j++)
        delete[] * (ap + j);
    delete[] ap;
}

// ======== ������� 5 ========
struct Person {
    char* name;
    double salary;
};

// ���� ������ � �����������
void inputPersons(Person* arr, int n) {
    char buffer[100];
    for (int i = 0; i < n; i++) {
        cout << "\n��������� #" << i + 1 << endl;
        cout << "������� ���: ";
        cin >> ws; // ������� ��������
        cin.getline(buffer, 100);

        arr[i].name = new char[strlen(buffer) + 1];
        strcpy_s(arr[i].name, strlen(buffer) + 1, buffer);

        cout << "������� ��������: ";
        cin >> arr[i].salary;
    }
}

// ����� ������
void printPersons(Person* arr, int n) {
    cout << "\n---------------------------------------\n";
    cout << left << setw(20) << "���" << setw(10) << "��������" << endl;
    cout << "---------------------------------------\n";
    for (int i = 0; i < n; i++)
        cout << left << setw(20) << arr[i].name << setw(10) << arr[i].salary << endl;
}

// ���������� � �� ����� (����� compstr) ��� �� ��������
void sortPersons(Person* arr, int n, bool byName) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool swapNeeded = false;

            if (byName) {
                // ���������� compstr() �� ������� 2
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
            cout << "������� 1 � �������� �������� (���������)\n\n";
            int size;
            cout << "������� ������ ��������: ";
            cin >> size;

            float* a1 = new float[size];
            float* a2 = new float[size];
            float* a3 = new float[size];

            cout << "\n������� �������� ������� �������:\n";
            for (int i = 0; i < size; i++) {
                cout << "a1[" << i << "] = ";
                cin >> *(a1 + i);
            }

            cout << "\n������� �������� ������� �������:\n";
            for (int i = 0; i < size; i++) {
                cout << "a2[" << i << "] = ";
                cin >> *(a2 + i);
            }

            addarrays(a1, a2, a3, size);

            cout << "\n�������������� ������:\n";
            for (int i = 0; i < size; i++)
                cout << a1[i] << " + " << a2[i] << " = " << a3[i] << endl;

            delete[] a1;
            delete[] a2;
            delete[] a3;
            break;
        }
        case 2: {
            cout << "������� 2 � ��������� ����� compstr()\n\n";
            char s1[100], s2[100];
            cout << "������� ������ ������: ";
            cin >> ws;
            cin.getline(s1, 100);
            cout << "������� ������ ������: ";
            cin.getline(s2, 100);

            int res = compstr(s1, s2);
            cout << "\n��������� ���������: ";
            if (res == 0)
                cout << "������ �����.\n";
            else if (res < 0)
                cout << "\"" << s1 << "\" ��� ������ �� ��������.\n";
            else
                cout << "\"" << s2 << "\" ��� ������ �� ��������.\n";
            break;
        }
        case 3:
            cout << "������� 3 � 10 �������� �� 10 ��������� (���������)\n\n";
            task3();
            break;
        case 4:
            cout << "������� 4 � ������������ �������� �������� (new)\n\n";
            task4();
            break;
        case 5: {
            cout << "������� 5 � ��������� Person (������������ ������, ����������)\n\n";
            int n;
            cout << "������� ���������� �����������: ";
            cin >> n;

            Person* people = new Person[n];
            inputPersons(people, n);

            cout << "\n������ ����������� �� ����������:\n";
            printPersons(people, n);

            int sortChoice;
            cout << "\n����������� ��:\n"
                << "1 � ����� (������������ compstr)\n"
                << "2 � ��������\n"
                << "��� �����: ";
            cin >> sortChoice;

            bool byName = (sortChoice == 1);
            sortPersons(people, n, byName);

            cout << "\n����� ����������:\n";
            printPersons(people, n);

            // ����������� ������
            for (int i = 0; i < n; i++)
                delete[] people[i].name;
            delete[] people;
            break;
        }
        case 0:
            cout << "����� �� ���������...\n";
            break;
        default:
            cout << "�������� �����!\n";
        }

        if (choice != 0) {
            cout << "\n������� Enter, ����� ��������� � ����...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("cls");
        }

    } while (choice != 0);

    return 0;
}
