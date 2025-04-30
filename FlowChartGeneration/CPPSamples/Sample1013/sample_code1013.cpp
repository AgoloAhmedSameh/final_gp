#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int p) {
    if (p < 2) {
        return false;
    }
    for (int k = 2; k < std::min(static_cast<int>(std::sqrt(p)) + 1, p - 1); ++k) {
        if (p % k == 0) {
            return false;
        }
    }
    return true;
}

int prime_fib(int n) {
    std::vector<int> f = {0, 1};
    while (true) {
        f.push_back(f[f.size() - 1] + f[f.size() - 2]);
        if (is_prime(f.back())) {
            n -= 1;
        }
        if (n == 0) {
            return f.back();
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << prime_fib(n) << std::endl;
    return 0;
}
