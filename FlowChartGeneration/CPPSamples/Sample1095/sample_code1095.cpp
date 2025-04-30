#include <vector>

int solution(const std::vector<int>& lst) {
    int sum = 0;
    for (size_t idx = 0; idx < lst.size(); ++idx) {
        if (idx % 2 == 0 && lst[idx] % 2 == 1) {
            sum += lst[idx];
        }
    }
    return sum;
}
