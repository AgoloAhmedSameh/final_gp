#include <cmath>

std::pair<double, double> volume_cone(double r, double h) {
    double volume = (1.0 / 3) * M_PI * r * r * h;
    return {volume, volume};
}
