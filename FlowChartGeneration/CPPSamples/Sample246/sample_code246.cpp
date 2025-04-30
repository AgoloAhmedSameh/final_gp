#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> lps(const string& str) {
    int n = str.length();
    vector<vector<int>> L(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        L[i][i] = 1;
    }

    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i <= n - cl; i++) {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2) {
                L[i][j] = 2;
            } else if (str[i] == str[j]) {
                L[i][j] = L[i + 1][j - 1] + 2;
            } else {
                L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }
        }
    }
    return {L[0][n - 1], 0}; // Return 0 as a placeholder for the second value
}
