#include <vector>
#include <tuple>

std::pair<int, int> count_samepair(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    int result = 0;
    size_t size = std::min({list1.size(), list2.size(), list3.size()});
    
    for (size_t i = 0; i < size; ++i) {
        if (list1[i] == list2[i] && list2[i] == list3[i]) {
            result++;
        }
    }
    return {result, 0};
}
