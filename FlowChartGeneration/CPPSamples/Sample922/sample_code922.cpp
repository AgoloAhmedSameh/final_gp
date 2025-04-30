#include <string>
#include <algorithm>

int super_seq(const std::string &X, const std::string &Y, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (X[m - 1] == Y[n - 1])
        return 1 + super_seq(X, Y, m - 1, n - 1);
    return 1 + std::min(super_seq(X, Y, m - 1, n), super_seq(X, Y, m, n - 1));
}
