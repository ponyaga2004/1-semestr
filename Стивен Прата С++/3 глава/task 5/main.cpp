#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	cout << "������� ���-�� ���������� ����(�����������):";
	double S;
	cin >> S;
	cout << "������� ���-�� ����������� �������(������):";
	int oil;
	cin >> oil;
	double a = S / oil;
	double b = oil / S;
	cout << "�� ���� ������ �� ������" << " " << a << " " << "����" << endl;
	cout << "�� ���� ��������� �� ���������" << " " << b << " " << "������" << endl;
	system("pause");
	return 0;
}