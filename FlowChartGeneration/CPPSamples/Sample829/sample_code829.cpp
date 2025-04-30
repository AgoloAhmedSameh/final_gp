#include <cmath>

std::pair<double, double> round_up(double a, int digits) {
    double n = std::pow(10, -digits);
    return std::make_pair(std::round(std::ceil(a / n) * n), digits);
}
