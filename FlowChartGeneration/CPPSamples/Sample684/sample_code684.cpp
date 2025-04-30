#include <vector>

std::pair<int, int> sum_Of_Primes(int n) {
    std::vector<bool> prime(n + 1, true);
    int p = 2;
    while (p * p <= n) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
        p++;
    }
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            sum += i;
        }
    }
    return {sum, 0}; // Returning a pair, second value is set to 0 as in original code.
}
