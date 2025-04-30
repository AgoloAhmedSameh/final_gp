#include <iostream>
#include <algorithm>

std::pair<int, int> sum(int a, int b) {
    int sum = 0;
    for (int i = 1; i < std::min(a, b); ++i) {
        if (a % i == 0 && b % i == 0) {
            sum += i;
        }
    }
    return std::make_pair(sum, 0);
}
