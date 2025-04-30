#include <vector>
#include <utility>

std::pair<int, bool> neg_nos(const std::vector<int>& list1) {
    for (int num : list1) {
        if (num < 0) {
            return {num, true};
        }
    }
    return {0, false}; // Return a default value if no negative number is found
}
