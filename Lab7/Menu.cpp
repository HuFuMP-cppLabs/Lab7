#include "Menu.h"
#include <iostream>
using namespace std;

int Menu::show() {
    cout << "=================================\n";
    cout << "         ���� ������������ 7     \n";
    cout << "=================================\n";
    cout << "1. �������� �������� (addarrays)\n";
    cout << "2. ��������� ����� (compstr)\n";
    cout << "3. 10 �������� �� 10 ���������\n";
    cout << "4. ������������ �������� ��������\n";
    cout << "5. ��������� Person + ����������\n";
    cout << "0. �����\n";
    cout << "---------------------------------\n";
    cout << "������� ����� �������: ";

    int choice;
    cin >> choice;
    return choice;
}
