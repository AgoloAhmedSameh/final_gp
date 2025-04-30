#include <tuple>
#include <string>

std::tuple<std::string, double> discriminant_value(double x, double y, double z) {
    double discriminant = (y * y) - (4 * x * z);
    if (discriminant > 0) {
        return std::make_tuple("Two solutions", discriminant);
    } else if (discriminant == 0) {
        return std::make_tuple("one solution", discriminant);
    } else {
        return std::make_tuple("no real solution", discriminant);
    }
}
