#include <vector>

std::pair<int, int> permutation_coefficient(int n, int k) {
    std::vector<std::vector<int>> P(n + 1, std::vector<int>(k + 1, 0));
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= std::min(i, k); ++j) {
            if (j == 0) {
                P[i][j] = 1;
            } else {
                P[i][j] = P[i - 1][j] + (j * P[i - 1][j - 1]);
            }
            if (j < k) {
                P[i][j + 1] = 0;
            }
        }
    }
    return {P[n][k], 0}; // Returning 0 as second value to match return type
}
