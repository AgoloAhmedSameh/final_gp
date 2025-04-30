#include <cmath>

std::pair<int, int> wind_chill(double v, double t) {
    double windchill = 13.12 + 0.6215 * t - 11.37 * pow(v, 0.16) + 0.3965 * t * pow(v, 0.16);
    return std::make_pair(static_cast<int>(round(windchill)), 0);
}
