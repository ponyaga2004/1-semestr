#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	cout << "������� ������ ������� � ����������� �����:";
	double e;
	cin >> e;
	e = e * 0.26;
	e = e / 64.12;
	e = 1 / e;
	cout << "������ ������� � ������������ �����:" << e << endl;
	system("pause");
	return 0;
}