#include <vector>
#include <algorithm>

std::vector<std::string> sorted_list_sum(std::vector<std::string> lst) {
    std::sort(lst.begin(), lst.end());
    std::vector<std::string> new_lst;
    for (const auto& i : lst) {
        if (i.length() % 2 == 0) {
            new_lst.push_back(i);
        }
    }
    std::sort(new_lst.begin(), new_lst.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    return new_lst;
}
