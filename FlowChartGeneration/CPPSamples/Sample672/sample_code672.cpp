#include <vector>
#include <string>
#include <iostream>

std::pair<int, int> convert(const std::vector<int>& list) {
    std::string s;
    for (int i : list) {
        s += std::to_string(i);
    }
    int res = std::stoi(s);
    return {res};
}
