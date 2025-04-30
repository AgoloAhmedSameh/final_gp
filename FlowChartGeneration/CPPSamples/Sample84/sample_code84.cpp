#include <cmath>

std::pair<double, double> surfacearea_sphere(double r) {
    double surfacearea = 4 * M_PI * r * r;
    return {surfacearea, surfacearea};
}
