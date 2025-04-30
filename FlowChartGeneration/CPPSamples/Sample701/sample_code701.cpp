#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_ind(int key, int i, int n, int k, vector<int>& arr) {
    int ind = -1;
    int start = i + 1;
    int end = n - 1;
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] - key <= k) {
            ind = mid;
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return ind;
}

pair<int, int> removals(vector<int>& arr, int n, int k) {
    int ans = n - 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int j = find_ind(arr[i], i, n, k, arr);
        if (j != -1) {
            ans = min(ans, n - (j - i + 1));
        }
    }
    return {ans, 0};
}
