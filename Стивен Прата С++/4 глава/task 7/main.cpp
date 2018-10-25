#include <iostream>
#include <string>

struct Pizza {
    std::string company;
    int d;
    float w;
};

int main() {
    Pizza pizza;

    std::cout << "Enter company name: ";
    getline(std::cin, pizza.company);
    std::cout << "Enter diameter: ";
    std::cin >> pizza.d;
    std::cout << "Enter weight: ";
    std::cin >> pizza.w;

    std::cout << pizza.company << ", " << pizza.d << ", " << pizza.w << std::endl;

    return 0;
}