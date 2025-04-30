#include <vector>
#include <algorithm>

std::pair<int, int> maximum_segments(int n, int a, int b, int c) {
    std::vector<int> dp(n + 10, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] != -1) {
            if (i + a <= n) {
                dp[i + a] = std::max(dp[i] + 1, dp[i + a]);
            }
            if (i + b <= n) {
                dp[i + b] = std::max(dp[i] + 1, dp[i + b]);
            }
            if (i + c <= n) {
                dp[i + c] = std::max(dp[i] + 1, dp[i + c]);
            }
        }
    }
    return {dp[n], -1}; // The second value is set to -1 to match the return type.
}
