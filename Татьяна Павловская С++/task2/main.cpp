#include <iostream>

float fabs(float x) {
    if (x < 0) return -x;
    return x;
}

void task2() {
    int n;

    std::cout << "Enter n:";
    std::cin >> n;

    float *array = new float[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Enter a[" << i << "]: ";
        std::cin >> array[i];
    }

    float a, b;
    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    // Point 1
    int count = 0;
    int maxIndex = 0;
    float maxValue = array[maxIndex];
    for (int i = 0; i < n; i++) {
        if (array[i] >= a && array[i] <= b) {
            count++;
        }

        if (array[i] >= maxValue) {
            maxIndex = i;
            maxValue = array[maxIndex];
        }
    }
    std::cout << "Count: " << count << std::endl;

    float sumAfterMax = 0;
    for (int i = maxIndex + 1; i < n; i++) {
        sumAfterMax += array[i];
    }
    std::cout << "Sum after max: " << sumAfterMax << std::endl;

    // SORTING
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (fabs(array[i]) < fabs(array[i + 1])) {
                float tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    task2();
    return 0;
}