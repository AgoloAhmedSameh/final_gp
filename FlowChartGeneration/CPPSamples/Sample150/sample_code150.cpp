#include <iostream>

int gcd(int p, int q) {
    while (q != 0) {
        int temp = q;
        q = p % q;
        p = temp;
    }
    return p;
}

bool is_coprime(int x, int y) {
    return gcd(x, y) == 1;
}
