#include <cmath>
#include <tuple>

std::tuple<double, double> otherside_rightangle(double w, double h) {
    double s = std::sqrt((w * w) + (h * h));
    return std::make_tuple(s);
}
