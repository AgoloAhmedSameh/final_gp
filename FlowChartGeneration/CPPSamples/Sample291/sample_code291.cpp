#include <utility>

std::pair<int, int> find(int n, int m) {
    int q = n / m;
    return std::make_pair(q, 0); // Assuming the second return value is 0 as the original code has only one return value
}
