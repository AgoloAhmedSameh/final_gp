#include <vector>
#include <algorithm>

std::pair<int, int> lbs(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> lis(n + 1, 1);
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    std::vector<int> lds(n + 1, 1);
    
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int maximum = lis[0] + lds[0] - 1;
    
    for (int i = 1; i < n; ++i) {
        maximum = std::max(lis[i] + lds[i] - 1, maximum);
    }

    return {maximum, 0};  // Returning a pair, second value is not used
}
