#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	int foot, inch, foont;
	const int n = 12;
	const double k = 2.2;
	cout << "������� ���-�� �����:" << endl;
	cin >> foot;
	cout << "������� ���-�� ������:" << endl;
	cin >> inch;
	cout << "������� ���-�� ������:" << endl;
	cin >> foont;
	inch = foot * n + inch;
	foont = foont / k;
	double metr = inch * 0.0254;
	double index = foont / (metr*metr);
	cout << index;
	system("pause");

	return 0;
}