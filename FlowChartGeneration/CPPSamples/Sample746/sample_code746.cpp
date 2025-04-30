#include <vector>
#include <algorithm>

std::tuple<int, int> lcs_of_three(const std::string &X, const std::string &Y, const std::string &Z, int m, int n, int o) {
    std::vector<std::vector<std::vector<int>>> L(m + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(o + 1, 0)));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= o; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    L[i][j][k] = 0;
                } else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1]) {
                    L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
                } else {
                    L[i][j][k] = std::max({L[i - 1][j][k], L[i][j - 1][k], L[i][j][k - 1]});
                }
            }
        }
    }
    return {L[m][n][o], 0}; // The second value is just a placeholder, as the original function returns a tuple with two values
}
