#include <iostream>
#include <vector>

std::pair<std::vector<int>, std::vector<int>> get_ludic(int n) {
    std::vector<int> ludics;
    for (int i = 1; i <= n; ++i) {
        ludics.push_back(i);
    }
    int index = 1;
    while (index != ludics.size()) {
        int first_ludic = ludics[index];
        int remove_index = index + first_ludic;
        while (remove_index < ludics.size()) {
            ludics.erase(ludics.begin() + remove_index);
            remove_index += first_ludic - 1;
        }
        index++;
    }
    return {ludics, {}};
}
