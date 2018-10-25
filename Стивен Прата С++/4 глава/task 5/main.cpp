#include <iostream>
#include <string>

struct CandyBar {
    std::string name;
    float weight;
    int calories;
};

int main() {
    CandyBar snack{"Mocha Munch", 2.3, 350};

    std::cout << snack.name << ", " << snack.weight << ", " << snack.calories << std::endl;

    return 0;
}