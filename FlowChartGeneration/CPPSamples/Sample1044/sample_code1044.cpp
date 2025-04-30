#include <vector>
#include <algorithm>

std::vector<int> strange_sort_list(std::vector<int>& lst) {
    std::vector<int> res;
    bool switch_flag = true;
    while (!lst.empty()) {
        if (switch_flag) {
            auto min_it = std::min_element(lst.begin(), lst.end());
            res.push_back(*min_it);
            lst.erase(min_it);
        } else {
            auto max_it = std::max_element(lst.begin(), lst.end());
            res.push_back(*max_it);
            lst.erase(max_it);
        }
        switch_flag = !switch_flag;
    }
    return res;
}
