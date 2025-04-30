#include <cmath>

bool is_not_prime(int n) {
    bool result = false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            result = true;
        }
    }
    return result;
}
