#include <iostream>
#include <vector>
#include <utility>
#include <string>

std::pair<int, int> max_Product(std::vector<int> arr) {
    int arr_len = arr.size();
    if (arr_len < 2) {
        throw std::runtime_error("No pairs exists");
    }
    int x = arr[0], y = arr[1];
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
