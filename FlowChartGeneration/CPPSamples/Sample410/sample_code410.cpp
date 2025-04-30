#include <string>
#include <sstream>
#include <algorithm>

std::string snake_to_camel(const std::string& word) {
    std::stringstream ss(word);
    std::string item;
    std::string result;

    while (std::getline(ss, item, '_')) {
        if (!result.empty()) {
            result += std::toupper(item[0]);
        } else {
            result += item;
        }
        if (item.size() > 1) {
            result += item.substr(1);
        }
    }
    return result;
}
