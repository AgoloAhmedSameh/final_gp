#include <vector>
#include <string>
#include <algorithm>

std::pair<std::vector<std::string>, std::vector<std::string>> remove_words(std::vector<std::string> list1, const std::vector<std::string>& removewords) {
    for (const auto& word : list1) {
        if (std::find(removewords.begin(), removewords.end(), word) != removewords.end()) {
            list1.erase(std::remove(list1.begin(), list1.end(), word), list1.end());
        }
    }
    return {list1, removewords};
}
