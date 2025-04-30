#include <vector>
#include <set>
#include <string>

std::string Seq_Linear(std::vector<int>& seq_nums) {
    for (size_t x = 1; x < seq_nums.size(); ++x) {
        seq_nums[x] = seq_nums[x] - seq_nums[x - 1];
    }
    
    std::set<int> unique_diff(seq_nums.begin() + 1, seq_nums.end());
    if (unique_diff.size() == 1) {
        return "Linear Sequence";
    } else {
        return "Non Linear Sequence";
    }
}
