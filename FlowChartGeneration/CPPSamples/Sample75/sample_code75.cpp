#include <tuple>

std::tuple<double, double> count_Squares(int m, int n) {
    if (n < m) {
        std::swap(m, n);
    }
    return std::make_tuple((m * (m + 1) * (2 * m + 1) / 6.0 + (n - m) * m * (m + 1) / 2.0));
}
