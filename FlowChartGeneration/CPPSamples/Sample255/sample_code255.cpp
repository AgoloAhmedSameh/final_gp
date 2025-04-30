#include <iostream>

std::pair<int, int> count_Primes_nums(int n) {
    int ctr = 0;
    for (int num = 0; num < n; num++) {
        if (num <= 1) {
            continue;
        }
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                break;
            }
        }
        if (i == num) {
            ctr++;
        }
    }
    return std::make_pair(ctr, 0);
}
