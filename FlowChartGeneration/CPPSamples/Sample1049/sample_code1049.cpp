#include <iostream>

bool is_prime(int n) {
    for (int j = 2; j < n; j++) {
        if (n % j == 0) {
            return false;
        }
    }
    return true;
}

bool is_multiply_prime(int a) {
    for (int i = 2; i < 101; i++) {
        if (!is_prime(i)) continue;
        for (int j = 2; j < 101; j++) {
            if (!is_prime(j)) continue;
            for (int k = 2; k < 101; k++) {
                if (!is_prime(k)) continue;
                if (i * j * k == a) return true;
            }
        }
    }
    return false;
}
