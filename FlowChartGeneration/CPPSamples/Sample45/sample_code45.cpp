#include <vector>
#include <set>

bool test_distinct(const std::vector<int>& data) {
    return data.size() == std::set<int>(data.begin(), data.end()).size();
}
