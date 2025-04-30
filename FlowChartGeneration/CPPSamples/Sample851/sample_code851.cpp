#include <vector>

std::pair<std::vector<int>, std::vector<int>::iterator> remove_negs(std::vector<int>& num_list) {
    for (auto it = num_list.begin(); it != num_list.end(); ) {
        if (*it < 0) {
            it = num_list.erase(it);
        } else {
            ++it;
        }
    }
    return {num_list, num_list.end()};
}
