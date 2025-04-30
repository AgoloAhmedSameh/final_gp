#include <vector>
#include <numeric>

std::pair<std::vector<double>, void> average_tuple(const std::vector<std::vector<double>>& nums) {
    std::vector<double> result;
    size_t n = nums.size();
    if (n == 0) return {result, {}};

    size_t m = nums[0].size();
    result.resize(m, 0.0);

    for (const auto& vec : nums) {
        for (size_t j = 0; j < m; ++j) {
            result[j] += vec[j];
        }
    }

    for (size_t j = 0; j < m; ++j) {
        result[j] /= n;
    }

    return {result, {}};
}
