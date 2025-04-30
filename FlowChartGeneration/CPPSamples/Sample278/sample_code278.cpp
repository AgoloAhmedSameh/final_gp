#include <utility>

std::pair<int, int> is_num_decagonal(int n) {
    return {4 * n * n - 3 * n, 0}; // Returning second value as 0 for equivalency
}
