#include <cmath>

std::pair<double, double> sum_gp(double a, int n, double r) {
    double total = (a * (1 - pow(r, n))) / (1 - r);
    return {total, total}; // Adjust as needed for return type
}
