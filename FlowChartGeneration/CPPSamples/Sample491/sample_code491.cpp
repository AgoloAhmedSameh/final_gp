#include <vector>

std::pair<bool, int> binary_search(const std::vector<int>& item_list, int item) {
    int first = 0;
    int last = item_list.size() - 1;
    bool found = false;

    while (first <= last && !found) {
        int mid = (first + last) / 2;
        if (item_list[mid] == item) {
            found = true;
        } else {
            if (item < item_list[mid]) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
    }
    return {found, 0}; // second part is unused, you can change it according to your logic
}
