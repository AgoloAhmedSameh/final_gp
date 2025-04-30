#include <complex>
#include <cmath>

std::pair<double, double> angle_complex(double a, double b) {
    std::complex<double> cn(a, b);
    double angle = std::atan2(b, a);
    return std::make_pair(angle, angle);
}
