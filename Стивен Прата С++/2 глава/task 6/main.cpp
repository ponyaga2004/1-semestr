// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void time()
{
	int h, m;
	cout << "Enter the number of hours: "; 
	cin >> h;
	cout << "Enter the number of minutes: "; 
	cin >> m;
	cout << "Time: " << h << ":" << m << endl;
	system("pause");
}
int main()
{
	setlocale(0, "rus");
	time();
    return 0;
}

