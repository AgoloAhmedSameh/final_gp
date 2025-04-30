#include <tuple>

std::tuple<int> find(int n, int m) {
    int r = n % m;
    return std::make_tuple(r);
}
