#include <cmath>

std::pair<double, double> surfacearea_cone(double r, double h) {
    double l = sqrt(r * r + h * h);
    double SA = M_PI * r * (r + l);
    return {SA};
}
