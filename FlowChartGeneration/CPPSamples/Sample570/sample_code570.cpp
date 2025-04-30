#include <vector>
#include <algorithm>

std::pair<int, int> max_sum_pair_diff_lessthan_K(std::vector<int>& arr, int N, int K) {
    std::sort(arr.begin(), arr.end());
    std::vector<int> dp(N, 0);
    dp[0] = 0;
    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1];
        if (arr[i] - arr[i - 1] < K) {
            if (i >= 2) {
                dp[i] = std::max(dp[i], dp[i - 2] + arr[i] + arr[i - 1]);
            } else {
                dp[i] = std::max(dp[i], arr[i] + arr[i - 1]);
            }
        }
    }
    return {dp[N - 1], 0}; // Returning a second value as 0 to match the return type
}
