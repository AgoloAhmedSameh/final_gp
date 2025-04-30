#include <vector>

std::pair<long long, long long> nCr_mod_p(int n, int r, int p) {
    if (r > n - r) {
        r = n - r;
    }
    std::vector<long long> C(r + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, r); j > 0; --j) {
            C[j] = (C[j] + C[j - 1]) % p;
        }
    }
    return {C[r], 0}; // returning 0 as a dummy value for the second element
}
