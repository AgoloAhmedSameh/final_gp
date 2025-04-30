#include <iostream>
#include <map>
#include <variant>
#include <vector>
#include <algorithm>

int dict_depth(const std::variant<std::map<std::string, std::variant<int, std::map<std::string, std::variant<int>>>>, int>& d) {
    if (auto dict = std::get_if<std::map<std::string, std::variant<int, std::map<std::string, std::variant<int>>>>>(&d)) {
        return 1 + (dict->empty() ? 0 : 
                    std::max_element(dict->begin(), dict->end(), 
                                     [](const auto& a, const auto& b) { 
                                         return dict_depth(a.second) < dict_depth(b.second); 
                                     })->second);
    }
    return 0;
}
