#include <vector>
#include <algorithm>
#include <string>

std::vector<std::vector<std::string>> float_sort(const std::vector<std::vector<std::string>>& price) {
    std::vector<std::vector<std::string>> sorted_price = price;
    std::sort(sorted_price.begin(), sorted_price.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        return std::stof(a[1]) > std::stof(b[1]);
    });
    return sorted_price;
}
