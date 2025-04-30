#include <vector>

std::vector<int> intersperse(const std::vector<int>& numbers, int delimiter) {
    if (numbers.empty()) {
        return {};
    }

    std::vector<int> result;

    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        result.push_back(numbers[i]);
        result.push_back(delimiter);
    }

    result.push_back(numbers.back());

    return result;
}
