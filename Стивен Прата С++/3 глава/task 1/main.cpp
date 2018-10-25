#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	cout << "enter height in inches:";
	const int k = 12;
	int n;
	cin >> n;
	int l = n / k;
	int m = n - l * k;
	cout << l << " "<<"foot." << endl;
	cout << m << " "<<"Inch." << endl;
	system("pause");
	return 0;
}