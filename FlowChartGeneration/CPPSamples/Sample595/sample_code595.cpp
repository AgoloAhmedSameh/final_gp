#include <iostream>
#include <tuple>
#include <vector>

size_t tuple_size(const std::vector<std::tuple<>>& tuple_list) {
    return sizeof(tuple_list);
}
