#include <vector>

std::pair<std::vector<int>, std::vector<int>> re_arrange_array(std::vector<int>& arr, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j = j + 1;
        }
    }
    return {arr};
}
