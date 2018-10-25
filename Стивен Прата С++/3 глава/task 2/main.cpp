#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	int foot, inch, foont;
	const int n = 12;
	const double k = 2.2;
	cout << "¬ведите кол-во футов:" << endl;
	cin >> foot;
	cout << "¬ведите кол-во дюймов:" << endl;
	cin >> inch;
	cout << "¬ведите кол-во фунтов:" << endl;
	cin >> foont;
	inch = foot * n + inch;
	foont = foont / k;
	double metr = inch * 0.0254;
	double index = foont / (metr*metr);
	cout << index;
	system("pause");

	return 0;
}