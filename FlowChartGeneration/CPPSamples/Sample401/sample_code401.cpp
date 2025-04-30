#include <vector>

std::pair<int, int> ncr_modp(int n, int r, int p) {
    std::vector<int> C(r + 1, 0);
    C[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, r); j > 0; --j) {
            C[j] = (C[j] + C[j - 1]) % p;
        }
    }
    
    return {C[r], 0}; // Assuming you want to return a pair, the second value is 0 since the original code doesn't have a second return value.
}
