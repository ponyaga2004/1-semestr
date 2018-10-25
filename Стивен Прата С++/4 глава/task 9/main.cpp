#include <iostream>
#include <string>

struct CandyBar {
    std::string name;
    float weight;
    int calories;
};

int main() {
    CandyBar *snacks = new CandyBar[3]{
            {"Mocha Munch", 2.3,  350},
            {"Second",      12.3, 1350},
            {"Another",     2.33, 30}
    };

    for (int i = 0; i < 3; i++) {
        std::cout << snacks[i].name << ", " << snacks[i].weight << ", " << snacks[i].calories << std::endl;
    }

    delete[] snacks;

    return 0;
}