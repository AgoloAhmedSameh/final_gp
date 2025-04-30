#include <iostream>
#include <typeinfo>
#include <vector>

int find_lists(const auto& Input) {
    if (typeid(Input) == typeid(std::vector<int>)) {
        return 1;
    } else {
        return Input.size();
    }
}
