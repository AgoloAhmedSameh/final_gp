#include <tuple>

std::tuple<double, double> parabola_focus(double a, double b, double c) {
    double x_focus = -b / (2 * a);
    double y_focus = (4 * a * c - b * b + 1) / (4 * a);
    return std::make_tuple(x_focus, y_focus);
}
