#include <vector>
#include <cstdlib>

bool has_close_elements(const std::vector<float>& numbers, float threshold) {
    for (size_t idx = 0; idx < numbers.size(); ++idx) {
        for (size_t idx2 = 0; idx2 < numbers.size(); ++idx2) {
            if (idx != idx2) {
                float distance = std::abs(numbers[idx] - numbers[idx2]);
                if (distance < threshold) {
                    return true;
                }
            }
        }
    }
    return false;
}
