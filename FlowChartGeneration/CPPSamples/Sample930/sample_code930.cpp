#include <cmath>

std::pair<double, double> sum_series(double number) {
    double total = 0;
    total = pow((number * (number + 1)) / 2, 2);
    return {total, total}; // returning total twice as a pair
}
