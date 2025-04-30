#include <cmath>

int find_Digits(int n) {
    if (n < 0) {
        return 0;
    }
    if (n <= 1) {
        return 1;
    }
    double x = (n * log10(n / exp(1)) + log10(2 * M_PI * n) / 2.0);
    return floor(x) + 1;
}
