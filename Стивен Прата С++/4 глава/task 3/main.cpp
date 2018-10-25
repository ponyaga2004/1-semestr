#include <iostream>
#include <cstring>

int main() {
    char firstName[1024];
    char lastName[1024];

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    char *result = new char[strlen(firstName) + 2 + strlen(lastName) + 1];
    result[0] = 0;

    strcpy(result, lastName);
    strcat(result, ", ");
    strcat(result, firstName);

    std::cout << "Here's the information in a single string: " << result << std::endl;

    delete[] result;

    return 0;
}