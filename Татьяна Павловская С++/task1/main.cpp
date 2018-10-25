#include <iostream>

int Fi(float a, float b, float c, float x) { // function which returns integer value
    if (x - 1 < 0 && b - x != 0) {
        return int(a * x * x + b);
    } else if (x - 1 > 0 && b + x == 0) {
        return int((x - a) / x);
    }
    return int(x / c);
}


float Ff(float a, float b, float c, float x) { // function which returns float value
    if (x - 1 < 0 && b - x != 0) {
        return a * x * x + b;
    } else if (x - 1 > 0 && b + x == 0) {
        return (x - a) / x;
    }
    return x / c;
}

void task1() {
    float a, b, c, x1, x2, dx;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter dx: ";
    std::cin >> dx;

    int ac = int(a);
    int bc = int(b);
    int cc = int(c);

    bool cond = 0 != ((ac | bc) ^ (bc & cc)); // condition for ((Ac OR Bc) Mod2 (Bc AND Cc)) != 0

    std::cout << x1 << " " << x2 << " " << dx << std::endl;
    for (float x = x1; x <= x2; x += dx) {
        if (cond) {
            float result = Ff(a, b, c, x);
            std::cout << x << "\t" << result << std::endl;
        } else {
            int result = Fi(a, b, c, x);
            std::cout << x << "\t" << result << std::endl;
        }
    };
}

int main() {
    task1();
    return 0;
}