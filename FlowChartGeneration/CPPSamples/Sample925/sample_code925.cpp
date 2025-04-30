#include <iostream>
using namespace std;

int binomial_coeffi(int n, int k) {
    if (k == 0 || k == n) 
        return 1;
    return binomial_coeffi(n - 1, k - 1) + binomial_coeffi(n - 1, k);
}

int rencontres_number(int n, int m) {
    if (n == 0 && m == 0) 
        return 1;
    if (n == 1 && m == 0) 
        return 0;
    if (m == 0) 
        return (n - 1) * (rencontres_number(n - 1, 0) + rencontres_number(n - 2, 0));
    return binomial_coeffi(n, m) * rencontres_number(n - m, 0);
}
