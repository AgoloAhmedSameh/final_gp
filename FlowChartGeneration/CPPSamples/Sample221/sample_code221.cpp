#include <tuple>
#include <typeinfo>

bool check_type(const std::tuple<>& test_tuple) {
    return true;
}

template<typename T, typename... Args>
bool check_type(const std::tuple<T, Args...>& test_tuple) {
    bool res = true;
    const std::type_info& first_type = typeid(T);
    
    std::apply([&](const auto&... elems) {
        ((res &= (typeid(elems) == first_type)), ...);
    }, test_tuple);
    
    return res;
}
