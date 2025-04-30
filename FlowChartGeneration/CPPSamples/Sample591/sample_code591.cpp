#include <vector>
using namespace std;

int binomial_Coeff(int n, int k) {
    vector<int> C(k + 1, 0);
    C[0] = 1; // nC0 is 1
    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, k); j > 0; --j) {
            C[j] = C[j] + C[j - 1];
        }
    }
    return C[k];
}

int sum_Of_product(int n) {
    return binomial_Coeff(2 * n, n - 1);
}
