#include <vector>

bool empty_dit(const std::vector<bool>& list1) {
    bool empty_dit = true;
    for (bool d : list1) {
        if (d) {
            empty_dit = false;
            break;
        }
    }
    return empty_dit;
}
