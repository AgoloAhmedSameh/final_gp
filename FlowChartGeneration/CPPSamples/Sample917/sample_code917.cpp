#include <vector>

std::pair<int, int> coin_change(std::vector<int>& S, int m, int n) {
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        table[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            int y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    return {table[n][m - 1]};
}
