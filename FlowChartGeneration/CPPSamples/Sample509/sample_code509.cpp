#include <vector>

std::pair<int, int> no_of_subsequences(std::vector<int>& arr, int k) {
    int n = arr.size();
    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (arr[j - 1] <= i && arr[j - 1] > 0) {
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
            }
        }
    }
    
    return {dp[k][n], 0}; // The second value in the pair is set to 0 as a placeholder.
}
