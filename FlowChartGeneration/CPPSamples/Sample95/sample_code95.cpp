#include <vector>

std::pair<int, int> divisor(int n) {
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            x++;
        }
    }
    return {x, x}; // returning a pair as there's no second value in original code
}
