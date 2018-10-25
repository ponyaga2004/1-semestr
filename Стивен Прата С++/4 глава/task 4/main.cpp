#include <iostream>
#include <string>

int main() {
    std::string firstName;
    std::string lastName;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::string result = lastName + ", " + firstName;

    std::cout << "Here's the information in a single string: " << result << std::endl;
    return 0;
}