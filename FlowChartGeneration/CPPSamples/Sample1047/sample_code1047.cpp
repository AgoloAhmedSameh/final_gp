#include <vector>

int smallest_change(std::vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size() / 2; i++) {
        if (arr[i] != arr[arr.size() - i - 1]) {
            ans += 1;
        }
    }
    return ans;
}
