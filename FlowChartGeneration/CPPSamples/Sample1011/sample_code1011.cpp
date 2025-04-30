#include <vector>
#include <algorithm>

std::vector<int> sort_even(const std::vector<int>& l) {
    std::vector<int> evens, odds, ans;
    
    for (size_t i = 0; i < l.size(); i += 2) {
        evens.push_back(l[i]);
    }
    
    for (size_t i = 1; i < l.size(); i += 2) {
        odds.push_back(l[i]);
    }
    
    std::sort(evens.begin(), evens.end());
    
    for (size_t i = 0; i < evens.size() && i < odds.size(); ++i) {
        ans.push_back(evens[i]);
        ans.push_back(odds[i]);
    }
    
    if (evens.size() > odds.size()) {
        ans.push_back(evens.back());
    }
    
    return ans;
}
