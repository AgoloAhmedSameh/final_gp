#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> sub_lists(const std::vector<int>& my_list) {
    std::vector<std::vector<int>> subs;
    int n = my_list.size();
    
    for (int i = 0; i <= n; ++i) {
        std::vector<bool> v(n);
        std::fill(v.begin(), v.begin() + i, true);
        do {
            std::vector<int> temp;
            for (int j = 0; j < n; ++j) {
                if (v[j]) {
                    temp.push_back(my_list[j]);
                }
            }
            subs.push_back(temp);
        } while (std::prev_permutation(v.begin(), v.end()));
    }
    
    return subs;
}
