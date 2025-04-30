#include <vector>
#include <tuple>

std::tuple<int, bool> pos_nos(const std::vector<int>& list1) {
    for (int num : list1) {
        if (num >= 0) {
            return std::make_tuple(num, true);
        }
    }
    return std::make_tuple(0, false); // to handle cases where no positive number is found
}
