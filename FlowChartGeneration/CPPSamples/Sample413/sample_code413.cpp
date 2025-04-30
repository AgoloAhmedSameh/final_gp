#include <vector>

int overlapping(std::vector<int> list1, std::vector<int> list2) {
    int c = 0;
    int d = 0;
    for (int i : list1) {
        c += 1;
    }
    for (int i : list2) {
        d += 1;
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            if (list1[i] == list2[j]) {
                return 1;
            }
        }
    }
    return 0;
}
