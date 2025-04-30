#include <tuple>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

std::tuple<std::vector<int>> str_to_tuple(const std::string& test_str) {
    std::vector<int> res;
    std::stringstream ss(test_str);
    std::string temp;
    
    while (std::getline(ss, temp, ',')) {
        res.push_back(std::stoi(temp));
    }
    
    return std::make_tuple(res);
}
