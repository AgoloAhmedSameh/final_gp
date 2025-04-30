#include <vector>

int binomial_coeff(int n, int k) {
    std::vector<std::vector<int>> C(n + 1, std::vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= std::min(i, k); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

double lobb_num(int n, int m) {
    return static_cast<double>((2 * m + 1) * binomial_coeff(2 * n, m + n)) / (m + n + 1);
}
