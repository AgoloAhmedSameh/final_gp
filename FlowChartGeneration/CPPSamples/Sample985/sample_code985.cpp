#include <string>

std::string string_xor(const std::string& a, const std::string& b) {
    auto xor_func = [](char i, char j) {
        return (i == j) ? '0' : '1';
    };

    std::string result;
    for (size_t k = 0; k < a.size(); ++k) {
        result += xor_func(a[k], b[k]);
    }

    return result;
}
