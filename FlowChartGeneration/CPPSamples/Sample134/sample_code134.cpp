#include <iostream>
#include <utility>

std::pair<int, int> hexagonal_num(int n) {
    return std::make_pair(n * (2 * n - 1), 0); // The second value is added to match the return type.
}
