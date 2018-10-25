#include <iostream>
using namespace std;

int main()
{
    char fname [20], lname [20], letter;
    int age;
    cout << "What is your first name?";
    cin.getline (fname, 20);
    cout << "What is your last name?";
    cin.getline (lname, 20);
    cout << "What letter grade do you deserve?";
    cin >> letter;
    cout <<"What is your age?";
    cin >> age;
    cout << "Name: "<< lname << ", "<< fname << endl;
    switch (letter) {
        case 'A':
            cout << "Grade: B \n";
            break;
        case 'B':
            cout << "Grade: C \n";
            break;
        case 'C':
            cout << "Grade: D \n";
            break;
        default:
            break;
    }
    cout << "Age: "<< age << ".\n";
    return 0;
}