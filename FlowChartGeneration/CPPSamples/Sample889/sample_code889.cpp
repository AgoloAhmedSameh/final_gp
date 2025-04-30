#include <vector>

int find_Extra(std::vector<int>& arr1, std::vector<int>& arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return i;
        }
    }
    return n;
}
