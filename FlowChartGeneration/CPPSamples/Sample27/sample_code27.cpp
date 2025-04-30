#include <iostream>
using namespace std;

int binomial_Coeff(int n, int k) {
    if (k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    return binomial_Coeff(n - 1, k - 1) + binomial_Coeff(n - 1, k);
}
