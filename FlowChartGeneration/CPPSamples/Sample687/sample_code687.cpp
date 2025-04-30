#include <complex>
#include <cmath>

std::pair<double, double> len_complex(double a, double b) {
    std::complex<double> cn(a, b);
    double length = std::abs(cn);
    return {length, 0}; // Just to match the return type, the second value is placeholder.
}
