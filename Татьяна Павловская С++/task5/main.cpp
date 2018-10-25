#include <iostream>

struct Note {
    char surname[1024];
    char name[1024];
    char phone[32];
    int birthday[3];
};


void task5() {

    Note structs[8];

    for (int i = 0; i < 8; i++) {
        std::cout << "Enter surname:";
        std::cin >> structs[i].surname;
        std::cout << "Enter name:";
        std::cin >> structs[i].name;
        std::cout << "Enter phone:";
        std::cin >> structs[i].phone;
        std::cout << "Enter birthday year:";
        std::cin >> structs[i].birthday[0];
        std::cout << "Enter birthday month:";
        std::cin >> structs[i].birthday[1];
        std::cout << "Enter birthday day:";
        std::cin >> structs[i].birthday[2];
    }

    int month;
    std::cout << "Enter required month: ";
    std::cin >> month;

    bool exists = false;

    for (int i = 0; i < 8; i++) {
        if (structs[i].birthday[1] == month) {
            std::cout << structs[i].surname << " "
                      << structs[i].name << " with phone "
                      << structs[i].phone << " at "
                      << structs[i].birthday[0] << "." << structs[i].birthday[1] << "." << structs[i].birthday[2]
                      << std::endl;
            exists = true;
        }
    }

    if (!exists) {
        std::cout << "Nobody" << std::endl;
    }
}

int main() {
    task5();
    return 0;
}
