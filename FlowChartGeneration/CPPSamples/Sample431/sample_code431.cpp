#include <utility>

std::pair<double, double> median_trapezium(double base1, double base2, double height) {
    double median = 0.5 * (base1 + base2);
    return std::make_pair(median, median);
}
