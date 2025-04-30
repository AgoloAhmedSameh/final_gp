#include <iostream>
#include <vector>

std::pair<int, int> smallest_multiple(int n) {
    if (n <= 2) {
        return {n, 0};
    }
    
    int i = n * 2;
    std::vector<int> factors;
    for (int number = n; number > 1; --number) {
        if (number * 2 > n) {
            factors.push_back(number);
        }
    }
    
    while (true) {
        for (auto a : factors) {
            if (i % a != 0) {
                i += n;
                break;
            }
            if (a == factors.back() && i % a == 0) {
                return {i, 0};
            }
        }
    }
}
