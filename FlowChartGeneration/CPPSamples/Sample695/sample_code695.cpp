#include <vector>
#include <string>

std::vector<std::string> zip_list(const std::vector<std::string>& list1, const std::vector<std::string>& list2) {
    std::vector<std::string> result;
    for (size_t i = 0; i < list1.size(); ++i) {
        result.push_back(list1[i] + list2[i]);
    }
    return result;
}
