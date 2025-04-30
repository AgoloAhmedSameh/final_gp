#include <cmath>

std::pair<int, int> max_Prime_Factors(int n) {
    int maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }
    if (n > 2) {
        maxPrime = n;
    }
    return std::make_pair(maxPrime, 0);
}
