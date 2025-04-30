#include <cmath>

int count_Odd_Squares(int n, int m) {
    return static_cast<int>(sqrt(m)) - static_cast<int>(sqrt(n - 1));
}
