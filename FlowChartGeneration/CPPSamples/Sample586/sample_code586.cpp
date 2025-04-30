#include <tuple>
#include <vector>

std::tuple<std::vector<int>> list_tuple(const std::vector<int>& listx) {
    return std::make_tuple(listx);
}
