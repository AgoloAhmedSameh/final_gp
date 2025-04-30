#include <cmath>

double nCr(int n, int r) {
    if (r > n / 2) {
        r = n - r;
    }
    double answer = 1;
    for (int i = 1; i <= r; ++i) {
        answer *= (n - r + i);
        answer /= i;
    }
    return answer;
}

double binomial_probability(int n, int k, double p) {
    return nCr(n, k) * pow(p, k) * pow(1 - p, n - k);
}
