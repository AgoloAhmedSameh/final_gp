#include <iostream>
#include <map>

std::map<std::string, int> add_dict(const std::map<std::string, int>& d1, const std::map<std::string, int>& d2) {
    std::map<std::string, int> add_dict = d1;

    for (const auto& pair : d2) {
        add_dict[pair.first] += pair.second;
    }
    
    return add_dict;
}
