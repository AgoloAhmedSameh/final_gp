#include <cmath>

std::pair<double, double> lateralsurface_cylinder(double r, double h) {
    double lateralsurface = 2 * 3.1415 * r * h;
    return {lateralsurface, lateralsurface}; // Assuming the return value is the same for both
}
