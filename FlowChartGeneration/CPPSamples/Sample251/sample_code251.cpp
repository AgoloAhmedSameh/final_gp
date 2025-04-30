#include <complex>
#include <tuple>

std::tuple<double, double> convert(std::complex<double> numbers) {
    double magnitude = std::abs(numbers);
    double phase = std::arg(numbers);
    return std::make_tuple(magnitude, phase);
}
