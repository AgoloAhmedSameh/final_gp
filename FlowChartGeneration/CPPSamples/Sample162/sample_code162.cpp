#include <cmath>

std::pair<double, double> area_polygon(int s, double l) {
    double area = s * (l * l) / (4 * tan(M_PI / s));
    return {area, area};
}
