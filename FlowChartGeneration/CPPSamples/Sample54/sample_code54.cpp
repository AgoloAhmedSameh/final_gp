#include <cmath>

std::pair<double, double> tn_gp(double a, int n, double r) {
    double tn = a * pow(r, n - 1);
    return std::make_pair(tn, tn);
}
