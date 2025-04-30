#include <iostream>

int dealnnoy_num(int n, int m) {
    if (m == 0 || n == 0) {
        return 1;
    }
    return dealnnoy_num(m - 1, n) + dealnnoy_num(m - 1, n - 1) + dealnnoy_num(m, n - 1);
}
