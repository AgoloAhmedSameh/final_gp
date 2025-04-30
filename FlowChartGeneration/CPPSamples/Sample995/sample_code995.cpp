#include <vector>
#include <algorithm>

std::vector<float> rescale_to_unit(const std::vector<float>& numbers) {
    float min_number = *std::min_element(numbers.begin(), numbers.end());
    float max_number = *std::max_element(numbers.begin(), numbers.end());
    std::vector<float> scaled_numbers;
    for (float x : numbers) {
        scaled_numbers.push_back((x - min_number) / (max_number - min_number));
    }
    return scaled_numbers;
}
