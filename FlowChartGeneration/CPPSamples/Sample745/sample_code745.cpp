#include <tuple>

std::tuple<double> sector_area(double r, double a) {
    double pi = 22.0 / 7.0;
    if (a >= 360) {
        return std::make_tuple(0.0); // Return None equivalent
    }
    double sectorarea = (pi * r * r) * (a / 360);
    return std::make_tuple(sectorarea);
}
