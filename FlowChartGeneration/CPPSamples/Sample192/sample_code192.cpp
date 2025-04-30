#include <iostream>
#include <tuple>
#include <set>
#include <vector>

std::tuple<int, int> remove_tuple(std::tuple<int, int> test_tup) {
    std::set<int> unique_elements = {std::get<0>(test_tup), std::get<1>(test_tup)};
    std::vector<int> res_vec(unique_elements.begin(), unique_elements.end());
    
    return std::make_tuple(res_vec[0], res_vec.size() > 1 ? res_vec[1] : 0); // Assuming tuple size can only be 2
}

int main() {
    std::tuple<int, int> my_tuple = std::make_tuple(1, 2);
    auto result = remove_tuple(my_tuple);
    std::cout << std::get<0>(result) << ", " << std::get<1>(result) << std::endl;
    return 0;
}
