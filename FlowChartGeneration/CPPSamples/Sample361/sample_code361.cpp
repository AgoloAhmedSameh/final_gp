#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> max_occurrences(vector<int>& nums) {
    int max_val = 0;
    int result = nums[0];
    unordered_map<int, int> count;

    for (int i : nums) {
        count[i]++;
        if (count[i] > max_val) {
            max_val = count[i];
            result = i;
        }
    }
    return {result, max_val};
}
