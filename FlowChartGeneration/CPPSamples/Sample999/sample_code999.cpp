#include <vector>
#include <cmath>

std::vector<int> factorize(int n) {
    std::vector<int> fact;
    int i = 2;
    while (i <= static_cast<int>(sqrt(n) + 1)) {
        if (n % i == 0) {
            fact.push_back(i);
            n /= i;
        } else {
            i += 1;
        }
    }

    if (n > 1) {
        fact.push_back(n);
    }
    return fact;
}
