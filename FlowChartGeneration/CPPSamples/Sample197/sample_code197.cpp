#include <cmath>
#include <tuple>

std::tuple<double, double> largest_triangle(double a, double b) {
    if (a < 0 || b < 0) {
        return {-1, -1};
    }
    double area = (3 * sqrt(3) * pow(a, 2)) / (4 * b);
    return {area, area}; 
}
