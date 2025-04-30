#include <string>
using namespace std;

int longest_common_subsequence(const string& X, const string& Y, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    } else if (X[m-1] == Y[n-1]) {
        return 1 + longest_common_subsequence(X, Y, m-1, n-1);
    } else {
        return max(longest_common_subsequence(X, Y, m, n-1), longest_common_subsequence(X, Y, m-1, n));
    }
}
