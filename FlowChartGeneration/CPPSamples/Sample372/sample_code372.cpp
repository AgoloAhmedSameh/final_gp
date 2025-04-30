#include <tuple>

std::tuple<double, double, double> volume_cuboid(double l, double w, double h) {
    double volume = l * w * h;
    return std::make_tuple(volume, l, w, h);
}
