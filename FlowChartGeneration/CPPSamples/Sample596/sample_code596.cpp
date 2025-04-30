#include <vector>
using namespace std;

pair<int, int> find_kth(vector<int>& arr1, vector<int>& arr2, int m, int n, int k) {
    vector<int> sorted1(m + n);
    int i = 0, j = 0, d = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            sorted1[d] = arr1[i];
            i++;
        } else {
            sorted1[d] = arr2[j];
            j++;
        }
        d++;
    }
    while (i < m) {
        sorted1[d] = arr1[i];
        d++;
        i++;
    }
    while (j < n) {
        sorted1[d] = arr2[j];
        d++;
        j++;
    }
    return make_pair(sorted1[k - 1], 0);
}
