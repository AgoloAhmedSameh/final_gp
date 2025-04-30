#include <vector>

std::pair<std::vector<int>, std::vector<int>> perfect_squares(int a, int b) {
    std::vector<int> lists;
    for (int i = a; i <= b; i++) {
        int j = 1;
        while (j * j <= i) {
            if (j * j == i) {
                lists.push_back(i);
            }
            j++;
        }
    }
    return {lists};
}
