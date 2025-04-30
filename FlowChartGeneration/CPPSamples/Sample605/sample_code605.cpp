#include <cmath>

std::pair<double, double> radian_degree(double degree) {
    double radian = degree * (M_PI / 180);
    return {radian};
}
