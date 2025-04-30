#include <tuple>

std::pair<int, int> count_X(const std::tuple<int, int, int, int>& tup, int x) {
    int count = 0;
    for (int i = 0; i < std::tuple_size<decltype(tup)>::value; ++i) {
        if (std::get<i>(tup) == x) {
            count++;
        }
    }
    return std::make_pair(count, 0);
}
