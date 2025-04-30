#include <vector>

int find_missing(std::vector<int>& ar, int N) {
    int l = 0;
    int r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ar[mid] != mid + 1 && ar[mid - 1] == mid) {
            return mid + 1;
        } else if (ar[mid] != mid + 1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
