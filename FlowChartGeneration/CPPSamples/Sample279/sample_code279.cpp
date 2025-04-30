#include <vector>
#include <utility>

std::pair<bool, int> sequential_search(const std::vector<int>& dlist, int item) {
    int pos = 0;
    bool found = false;
    while (pos < dlist.size() && !found) {
        if (dlist[pos] == item) {
            found = true;
        } else {
            pos = pos + 1;
        }
    }
    return {found, pos};
}
