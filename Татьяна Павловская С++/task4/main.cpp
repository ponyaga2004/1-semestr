#include <iostream>
#include <math.h>

struct Point {
    float x;
    float y;
};

struct Circle {
    float x;
    float y;
    float r;
};

// Функция определения пересечения прямой через две точки и окружности
bool cross(Point p1, Point p2, Circle c) {
    // Сначала сдвигаем начало системы координат в центр окружности
    float p1x = p1.x - c.x;
    float p1y = p1.y - c.y;
    float p2x = p2.x - c.x;
    float p2y = p2.y - c.y;

    // потом ищем расстояние от центра координат до прямой
    float dx = p1x - p2x;
    float dy = p1y - p2y;
    float distance = fabs(p1x * p2y - p1y * p2x) / sqrt(dx * dx + dy * dy);

    // далее сравниваем с радиусом
    return distance < c.r;
}

void task4() {
    int nPoints;
    std::cout << "Введите количество точек: ";
    std::cin >> nPoints;

    Point *points = new Point[nPoints];
    for (int i = 0; i < nPoints; i++) {
        std::cout << "Введите x для точки " << i << ": ";
        std::cin >> points[i].x;
        std::cout << "Введите y для точки " << i << ": ";
        std::cin >> points[i].y;
    }

    int nCircles;
    std::cout << "Введите количество окружностей: ";
    std::cin >> nCircles;

    Circle *circles = new Circle[nCircles];
    for (int i = 0; i < nCircles; ++i) {
        std::cout << "Введите x для окружности " << i << ": ";
        std::cin >> circles[i].x;
        std::cout << "Введите y для окружности " << i << ": ";
        std::cin >> circles[i].y;
        std::cout << "Введите r для окружности " << i << ": ";
        std::cin >> circles[i].r;
    }

    int maxCrosses = 0; // Изначально максимальное число пересечений 0
    int p1 = -1; // индекс первой искомой точки
    int p2 = -1; // индекс второй искомой точки

    for (int point1 = 0;
         point1 < nPoints - 1; point1++) { // point1 - индекс первой точки (кроме последней, так как будет вторая)
        for (int point2 = point1 + 1;
             point2 < nPoints; point2++) { // point2 - индекс второй точки, всегда больше первого индекса

            int crosses = 0; // количество пересечений для данной пары точек
            for (int circle = 0; circle < nCircles; circle++) {
                if (cross(points[point1], points[point2], circles[circle])) {
                    crosses++;
                }
            }

            if (crosses > maxCrosses) {
                maxCrosses = crosses;
                p1 = point1;
                p2 = point2;
            }
        }
    }

    if (maxCrosses > 0) {
        std::cout << "(" << points[p1].x << "," << points[p1].y << ")" << std::endl;
        std::cout << "(" << points[p2].x << "," << points[p2].y << ")" << std::endl;
    } else {
        std::cout << "Пересечений нет" << std::endl;
    }

    delete[] circles;
    delete[] points;
}


int main() {
    task4();
    return 0;
}