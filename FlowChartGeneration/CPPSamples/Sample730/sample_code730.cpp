#include <cmath>

std::pair<double, double> lateralsurface_cone(double r, double h) {
    double l = sqrt(r * r + h * h);
    double LSA = M_PI * r * l;
    return {LSA, l};
}
