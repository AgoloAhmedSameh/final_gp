#include <vector>
#include <algorithm>

std::pair<int, int> min_sum_path(const std::vector<std::vector<int>>& A) {
    std::vector<int> memo(A.back());
    int n = A.size() - 1;
    
    for (int i = n - 1; i >= 0; --i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            memo[j] = A[i][j] + std::min(memo[j], memo[j + 1]);
        }
    }
    
    return {memo[0], 0}; // the second value is just a placeholder since the original Python function returns a tuple of two values
}
