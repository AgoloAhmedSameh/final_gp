#include <iostream>
#include <algorithm>

int recur_gcd(int a, int b) {
    int low = std::min(a, b);
    int high = std::max(a, b);
    if (low == 0) {
        return high;
    } else if (low == 1) {
        return 1;
    } else {
        return recur_gcd(low, high % low);
    }
}
