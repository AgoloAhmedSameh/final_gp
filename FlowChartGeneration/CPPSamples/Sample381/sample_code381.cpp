#include <vector>

int find_rotation_count(std::vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while (left <= right) {
        if (A[left] <= A[right]) {
            return left;
        }
        int mid = (left + right) / 2;
        int next = (mid + 1) % A.size();
        int prev = (mid - 1 + A.size()) % A.size();
        if (A[mid] <= A[next] && A[mid] <= A[prev]) {
            return mid;
        } else if (A[mid] <= A[right]) {
            right = mid - 1;
        } else if (A[mid] >= A[left]) {
            left = mid + 1;
        }
    }
    return -1;
}
