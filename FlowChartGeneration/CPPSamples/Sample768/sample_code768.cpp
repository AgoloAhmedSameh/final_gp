#include <vector>
#include <set>
#include <algorithm>

std::vector<int> Diff(const std::vector<int>& li1, const std::vector<int>& li2) {
    std::set<int> set1(li1.begin(), li1.end());
    std::set<int> set2(li2.begin(), li2.end());
    
    std::vector<int> diff;
    
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(diff));
    std::set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), std::back_inserter(diff));
    
    return diff;
}
