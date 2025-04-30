#include <vector>
#include <algorithm>

std::pair<std::vector<int>, std::vector<int>> extract_elements(const std::vector<int>& numbers, int n) {
    std::vector<int> result;
    std::vector<std::pair<int, int>> counts; // Pair of (element, count)

    if (!numbers.empty()) {
        int current = numbers[0];
        int count = 1;

        for (size_t i = 1; i < numbers.size(); ++i) {
            if (numbers[i] == current) {
                count++;
            } else {
                counts.emplace_back(current, count);
                current = numbers[i];
                count = 1;
            }
        }
        counts.emplace_back(current, count); // Add the last element
    }

    for (const auto& p : counts) {
        if (p.second == n) {
            result.push_back(p.first);
        }
    }

    return {result, {}};
}
