#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>

std::string matrix_to_list(const std::vector<std::vector<int>>& test_list) {
    std::vector<int> temp;
    for (const auto& sub : test_list) {
        for (const auto& ele : sub) {
            temp.push_back(ele);
        }
    }

    std::vector<std::tuple<int>> res;
    for (size_t i = 0; i < temp.size(); ++i) {
        res.push_back(std::make_tuple(temp[i]));
    }

    std::ostringstream oss;
    oss << "(";
    for (const auto& t : res) {
        oss << std::get<0>(t) << ",";
    }
    std::string result = oss.str();
    result.pop_back(); // Remove the last comma
    result += ")";
    
    return result;
}
