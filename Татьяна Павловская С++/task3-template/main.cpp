#include <iostream>

template <typename T>
int getElemT(T *matrix, int cols, int r, int c) {
    return matrix[r * cols + c];
}

template <typename T>
int setElemT(T *matrix, int cols, int r, int c, T value) {
    matrix[r * cols + c] = value;
}

template <typename T>
void shiftRowRightT(T *matrix, int cols, int row) {
    int save = getElemT(matrix, cols, row, cols - 1);

    for (int i = cols - 1; i > 0; i--) {
        int elem = getElemT(matrix, cols, row, i - 1);
        setElemT(matrix, cols, row, i, elem);
    }

    setElemT(matrix, cols, row, 0, save);
}

template <typename T>
void shiftColDownT(T *matrix, int cols, int rows, int col) {
    int save = getElemT(matrix, cols, rows - 1, col);

    for (int i = rows - 1; i > 0; i--) {
        int elem = getElemT(matrix, cols, i - 1, col);
        setElemT(matrix, cols, i, col, elem);
    }

    setElemT(matrix, cols, 0, col, save);
}

template <typename T>
void shiftMatrixRightT(T *matrix, int rows, int cols, int n) {
    for (int i = 0; i < n % cols; i++) {
        for (int row = 0; row < rows; row++) {
            shiftRowRightT(matrix, cols, row);
        }
    }
}

template <typename T>
void shiftMatrixDownT(T *matrix, int rows, int cols, int n) {
    for (int i = 0; i < n % rows; i++) {
        for (int col = 0; col < cols; col++) {
            shiftColDownT(matrix, cols, rows, col);
        }
    }
}


void task3T() {

    int rows, cols;

    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter cols: ";
    std::cin >> cols;

    int *matrix = new int[rows * cols];
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int elem;
            std::cout << "Enter matrix[" << row << "][" << col << "]: ";
            std::cin >> elem;
            setElemT(matrix, cols, row, col, elem);
        }
    }

    int mode;
    std::cout << "Enter mode (0 - right, 1 - down): ";
    std::cin >> mode;

    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (mode == 0) {
        shiftMatrixRightT(matrix, rows, cols, n);
    } else if (mode == 1) {
        shiftMatrixDownT(matrix, rows, cols, n);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << getElemT(matrix, cols, row, col) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    task3T();
    return 0;
}