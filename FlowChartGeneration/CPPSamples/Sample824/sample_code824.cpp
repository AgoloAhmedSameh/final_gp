#include <vector>
using namespace std;

pair<vector<int>, vector<int>> access_elements(const vector<int>& nums, const vector<int>& list_index) {
    vector<int> result;
    for (int i : list_index) {
        result.push_back(nums[i]);
    }
    return {result, result}; // You might want to replace the second 'result' with something else based on your requirements
}
