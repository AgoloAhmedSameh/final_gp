#include <iostream>
using namespace std;

int binary_search(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = (low + high) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && (arr[mid] == x)) {
            return mid;
        } else if (x > arr[mid]) {
            return binary_search(arr, mid + 1, high, x);
        } else {
            return binary_search(arr, low, mid - 1, x);
        }
    }
    return -1;
}

bool is_majority(int arr[], int n, int x) {
    int i = binary_search(arr, 0, n - 1, x);
    if (i == -1) {
        return false;
    }
    if ((i + n / 2) <= (n - 1) && arr[i + n / 2] == x) {
        return true;
    } else {
        return false;
    }
}
