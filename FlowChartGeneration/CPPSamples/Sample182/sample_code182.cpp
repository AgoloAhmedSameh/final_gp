#include <iostream>
#include <vector>
using namespace std;

pair<int, int> count_pairs(vector<int>& arr, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k) {
                count++;
            }
        }
    }
    return make_pair(count, 0);
}
