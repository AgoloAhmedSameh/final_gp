#include <vector>
#include <algorithm>

std::vector<int> move_last(std::vector<int> num_list) {
    int count = std::count(num_list.begin(), num_list.end(), num_list[0]);
    std::vector<int> a(count, num_list[0]);
    std::vector<int> x;

    for (const auto& i : num_list) {
        if (i != num_list[0]) {
            x.push_back(i);
        }
    }
    x.insert(x.end(), a.begin(), a.end());
    return x;
}
