#include <iostream>

std::pair<int, int> odd_bit_set_number(int n) {
    int count = 0, res = 0, temp = n;
    while (temp > 0) {
        if (count % 2 == 0) {
            res |= (1 << count);
        }
        count++;
        temp >>= 1;
    }
    return {n | res, 0}; // Adjust as necessary if you want to return something else
}
