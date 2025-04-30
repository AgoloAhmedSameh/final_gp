#include <cmath>
#include <iostream>

double triangle_area(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return -1;
    }
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    area = round(area * 100) / 100; // rounding to 2 decimal places
    return area;
}
