#include <iostream>

long long factorial(int start, int end) {
    long long res = 1;
    for (int i = start; i <= end; i++) {
        res *= i;
    }
    return res;
}

std::pair<int, int> sum_of_square(int n) {
    return static_cast<int>(factorial(n + 1, 2 * n) / factorial(1, n));
}
