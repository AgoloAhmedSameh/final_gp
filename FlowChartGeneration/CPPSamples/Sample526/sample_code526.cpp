#include <vector>

std::pair<int, int> get_pairs_count(const std::vector<int>& arr, int n, int sum) {
    int count = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                count++;
            }
        }
    }
    return {count, 0};
}
