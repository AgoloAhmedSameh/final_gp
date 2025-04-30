#include <vector>
#include <limits>
#include <type_traits>

std::pair<int, bool> min_val(const std::vector<int>& listval) {
    int min_val = std::numeric_limits<int>::max();
    bool found = false;

    for (const auto& i : listval) {
        if (std::is_same<decltype(i), int>::value) {
            if (i < min_val) {
                min_val = i;
                found = true;
            }
        }
    }

    return found ? std::make_pair(min_val, true) : std::make_pair(0, false);
}
