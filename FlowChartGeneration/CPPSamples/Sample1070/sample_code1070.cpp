#include <vector>

std::vector<int> count_up_to(int n) {
    std::vector<int> primes;
    for (int i = 2; i < n; i++) {
        bool is_prime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
        }
    }
    return primes;
}
