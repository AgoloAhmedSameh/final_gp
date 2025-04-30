#include <cmath>

int starts_one_ends(int n) {
    if (n == 1) return 1;
    return 18 * static_cast<int>(pow(10, n - 2));
}
