#include <tuple>
#include <vector>
#include <functional>

std::tuple<> even_ele(const std::tuple<> &test_tuple, std::function<bool(int)> even_fnc) {
    std::tuple<> res; 
    // Assuming you have a way to iterate over the tuple
    for (const auto &ele : test_tuple) { 
        if (std::holds_alternative<std::tuple<>>(ele)) { 
            res = std::tuple_cat(res, std::make_tuple(even_ele(std::get<std::tuple<>>(ele), even_fnc))); 
        } else if (even_fnc(std::get<int>(ele))) { 
            res = std::tuple_cat(res, std::make_tuple(std::get<int>(ele))); 
        } 
    } 
    return res; 
}

std::tuple<> extract_even(const std::tuple<> &test_tuple) {
    auto res = even_ele(test_tuple, [](int x) { return x % 2 == 0; });
    return res; 
}
