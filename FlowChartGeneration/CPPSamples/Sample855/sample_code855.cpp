#include <vector>
using namespace std;

pair<int, int> find_Min_Swaps(vector<int>& arr, int n) {
    vector<int> noOfZeroes(n, 0);
    int count = 0;
    noOfZeroes[n - 1] = 1 - arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        noOfZeroes[i] = noOfZeroes[i + 1];
        if (arr[i] == 0) {
            noOfZeroes[i] += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count += noOfZeroes[i];
        }
    }
    return {count, 0}; // Returning 0 as the second value since the original function had an unused value
}
