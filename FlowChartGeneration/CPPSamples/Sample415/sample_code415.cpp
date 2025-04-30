#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1000000;

std::pair<int, int> breakSum(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = std::max(dp[i / 2] + dp[i / 3] + dp[i / 4], i);
    }
    return {dp[n], 0}; // returning second value as 0 to match the original function signature
}

int main() {
    int n;
    std::cin >> n;
    auto result = breakSum(n);
    std::cout << result.first << std::endl;
    return 0;
}
