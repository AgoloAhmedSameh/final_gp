#include <vector>
#include <set>

bool all_unique(const std::vector<int>& test_list) {
    return test_list.size() == std::set<int>(test_list.begin(), test_list.end()).size();
}
