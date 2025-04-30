#include <tuple>

std::tuple<int, int> count_Squares(int m, int n) {
    if (n < m) {
        int temp = m;
        m = n;
        n = temp;
    }
    return std::make_tuple(n * (n + 1) * (3 * m - n + 1) / 6);
}
