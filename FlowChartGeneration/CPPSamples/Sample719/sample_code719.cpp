#include <tuple>
#include <vector>
#include <map>

std::tuple<std::tuple<std::map<std::string, int>>, std::map<std::string, int>> add_dict_to_tuple(std::tuple<std::map<std::string, int>> test_tup, std::map<std::string, int> test_dict) {
    std::vector<std::map<std::string, int>> vec;
    vec.push_back(std::get<0>(test_tup));
    vec.push_back(test_dict);
    return std::make_tuple(vec);
}
