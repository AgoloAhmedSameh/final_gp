#include <vector>

int smallest_missing(const std::vector<int>& A, int left_element, int right_element) {
    if (left_element > right_element) {
        return left_element;
    }
    int mid = left_element + (right_element - left_element) / 2;
    if (A[mid] == mid) {
        return smallest_missing(A, mid + 1, right_element);
    } else {
        return smallest_missing(A, left_element, mid - 1);
    }
}
