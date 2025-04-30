#include <vector>
#include <utility>

std::pair<int, int> max_product(const std::vector<int>& arr) {
    int arr_len = arr.size();
    if (arr_len < 2) {
        return std::make_pair(0, 0); // or handle error as needed
    }
    int x = arr[0];
    int y = arr[1];
    for (int i = 0; i < arr_len; i++) {
        for (int j = i + 1; j < arr_len; j++) {
            if (arr[i] * arr[j] > x * y) {
                x = arr[i];
                y = arr[j];
            }
        }
    }
    return std::make_pair(x, y);
}
