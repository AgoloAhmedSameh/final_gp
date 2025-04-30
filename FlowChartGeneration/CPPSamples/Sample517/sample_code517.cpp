#include <cmath>

std::pair<double, double> sqrt_root(double num) {
    double result = pow(num, 0.5);
    return std::make_pair(result, result);
}
