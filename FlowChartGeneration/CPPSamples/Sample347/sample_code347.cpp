#include <iostream>
using namespace std;

long long bin_coff(int n, int r) {
    long long val = 1;
    if (r > (n - r)) {
        r = (n - r);
    }
    for (int i = 0; i < r; i++) {
        val *= (n - i);
        val /= (i + 1);
    }
    return val;
}

long long find_ways(int M) {
    int n = M / 2;
    long long a = bin_coff(2 * n, n);
    long long b = a / (n + 1);
    return b;
}
