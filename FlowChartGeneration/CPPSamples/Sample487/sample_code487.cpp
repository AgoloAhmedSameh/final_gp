#include <cmath>

double area_pentagon(double a) {
    double area = (sqrt(5 * (5 + 2 * sqrt(5))) * pow(a, 2)) / 4.0;
    return area;
}
