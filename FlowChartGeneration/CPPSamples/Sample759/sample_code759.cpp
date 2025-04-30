#include <set>
#include <vector>
#include <string>

std::string unique_Element(std::vector<int> arr, int n) {
    std::set<int> s(arr.begin(), arr.end());
    if (s.size() == 1) {
        return "YES";
    } else {
        return "NO";
    }
}
