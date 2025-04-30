#include <vector>
#include <string>

std::string exchange(const std::vector<int>& lst1, const std::vector<int>& lst2) {
    int odd = 0;
    int even = 0;
    for (int i : lst1) {
        if (i % 2 == 1) {
            odd++;
        }
    }
    for (int i : lst2) {
        if (i % 2 == 0) {
            even++;
        }
    }
    if (even >= odd) {
        return "YES";
    }
    return "NO";
}
