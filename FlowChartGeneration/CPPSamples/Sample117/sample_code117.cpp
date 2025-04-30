#include <iostream>
#include <sstream>
#include <vector>

std::pair<std::vector<std::string>, std::vector<std::string>> string_to_list(const std::string& str) {
    std::vector<std::string> lst;
    std::stringstream ss(str);
    std::string item;

    while (ss >> item) {
        lst.push_back(item);
    }

    return {lst, {}};
}
