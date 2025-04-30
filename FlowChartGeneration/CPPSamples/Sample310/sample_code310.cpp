#include <iostream>

std::pair<int, int> set_left_most_unset_bit(int n) {
    if (!(n & (n + 1))) {
        return {n, 0};
    }
    int pos = 0, temp = n, count = 0;
    while (temp) {
        if (!(temp & 1)) {
            pos = count;
        }
        count += 1; 
        temp >>= 1;
    }
    return {n | (1 << pos), 0};
}
