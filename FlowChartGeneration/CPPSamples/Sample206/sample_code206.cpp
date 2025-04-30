#include <vector>
#include <string>
using namespace std;

pair<int, int> find_longest_repeating_subseq(const string& str) {
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return {dp[n][n], 0}; // The second value is not used in the original code
}
