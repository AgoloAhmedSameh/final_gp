#include <vector>
#include <algorithm>
#include <stdexcept>
#include <typeinfo>

int max_val(const std::vector<int>& listval) {
    if (listval.empty()) {
        throw std::invalid_argument("listval cannot be empty");
    }
    return *std::max_element(listval.begin(), listval.end());
}
