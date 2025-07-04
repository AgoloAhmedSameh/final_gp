#include <cmath>

double geometric_sum(int n) {
    if (n < 0) {
        return 0;
    } else {
        return 1 / pow(2, n) + geometric_sum(n - 1);
    }
}
