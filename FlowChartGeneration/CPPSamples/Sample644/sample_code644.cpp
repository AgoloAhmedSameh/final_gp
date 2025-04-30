#include <vector>

long long get_product(const std::vector<int>& val) {
    long long res = 1;
    for (const auto& ele : val) {
        res *= ele;
    }
    return res;
}

std::pair<long long> find_k_product(const std::vector<std::vector<int>>& test_list, int K) {
    std::vector<int> sub_k_values;
    for (const auto& sub : test_list) {
        sub_k_values.push_back(sub[K]);
    }
    long long res = get_product(sub_k_values);
    return {res};
}
