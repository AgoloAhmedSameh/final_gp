#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <variant>

using namespace std;

using TestTuple = std::variant<int, std::vector<std::variant<int, std::vector<int>>>>;

void flatten(const TestTuple& tup, vector<int>& flat) {
    if (std::holds_alternative<int>(tup)) {
        flat.push_back(std::get<int>(tup));
    } else {
        for (const auto& elem : std::get<vector<TestTuple>>(tup)) {
            flatten(elem, flat);
        }
    }
}

unordered_map<int, int> count_element_freq(const TestTuple& test_tuple) {
    vector<int> flat;
    flatten(test_tuple, flat);
    unordered_map<int, int> res;
    for (const auto& ele : flat) {
        res[ele]++;
    }
    return res;
}
