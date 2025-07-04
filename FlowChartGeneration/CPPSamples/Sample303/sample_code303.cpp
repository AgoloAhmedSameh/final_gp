#include <vector>
using namespace std;

pair<int, int> find_Element(vector<int>& arr, vector<vector<int>>& ranges, int rotations, int index) {
    for (int i = rotations - 1; i >= 0; i--) {
        int left = ranges[i][0];
        int right = ranges[i][1];
        if (left <= index && right >= index) {
            if (index == left) {
                index = right;
            } else {
                index = index - 1;
            }
        }
    }
    return make_pair(arr[index], index);
}
