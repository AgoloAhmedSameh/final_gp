#include <iostream>
using namespace std;

pair<int, int> get_Inv_Count(int arr[], int n) {
    int inv_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inv_count += 1;
            }
        }
    }
    return make_pair(inv_count, 0);
}
