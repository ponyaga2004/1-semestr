#include <iostream>

int getElem(int *matrix, int cols, int r, int c) {
    return matrix[r * cols + c];
}

int setElem(int *matrix, int cols, int r, int c, int value) {
    matrix[r * cols + c] = value;
}

void shiftRowRight(int *matrix, int cols, int row) {
    int save = getElem(matrix, cols, row, cols - 1);

    for (int i = cols - 1; i > 0; i--) {
        int elem = getElem(matrix, cols, row, i - 1);
        setElem(matrix, cols, row, i, elem);
    }

    setElem(matrix, cols, row, 0, save);
}

void shiftColDown(int *matrix, int cols, int rows, int col) {
    int save = getElem(matrix, cols, rows - 1, col);

    for (int i = rows - 1; i > 0; i--) {
        int elem = getElem(matrix, cols, i - 1, col);
        setElem(matrix, cols, i, col, elem);
    }

    setElem(matrix, cols, 0, col, save);
}

void shiftMatrixRight(int *matrix, int rows, int cols, int n) {
    for (int i = 0; i < n % cols; i++) {
        for (int row = 0; row < rows; row++) {
            shiftRowRight(matrix, cols, row);
        }
    }
}

void shiftMatrixDown(int *matrix, int rows, int cols, int n) {
    for (int i = 0; i < n % rows; i++) {
        for (int col = 0; col < cols; col++) {
            shiftColDown(matrix, cols, rows, col);
        }
    }
}


void task3() {

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
            setElem(matrix, cols, row, col, elem);
        }
    }

    int mode;
    std::cout << "Enter mode (0 - right, 1 - down): ";
    std::cin >> mode;

    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (mode == 0) {
        shiftMatrixRight(matrix, rows, cols, n);
    } else if (mode == 1) {
        shiftMatrixDown(matrix, rows, cols, n);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << getElem(matrix, cols, row, col) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    task3();
    return 0;
}