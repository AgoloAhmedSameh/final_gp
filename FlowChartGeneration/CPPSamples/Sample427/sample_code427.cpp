#include <vector>

std::vector<int> shell_sort(std::vector<int>& my_list) {
    int gap = my_list.size() / 2;
    while (gap > 0) {
        for (int i = gap; i < my_list.size(); i++) {
            int current_item = my_list[i];
            int j = i;
            while (j >= gap && my_list[j - gap] > current_item) {
                my_list[j] = my_list[j - gap];
                j -= gap;
            }
            my_list[j] = current_item;
        }
        gap /= 2;
    }
    return my_list;
}
