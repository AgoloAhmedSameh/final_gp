#include <vector>
#include <string>
#include <algorithm>

std::vector<int> unique_digits(const std::vector<int>& x) {
    std::vector<int> odd_digit_elements;
    for (int i : x) {
        std::string str_i = std::to_string(i);
        bool all_odd = true;
        for (char c : str_i) {
            if ((c - '0') % 2 == 0) {
                all_odd = false;
                break;
            }
        }
        if (all_odd) {
            odd_digit_elements.push_back(i);
        }
    }
    std::sort(odd_digit_elements.begin(), odd_digit_elements.end());
    return odd_digit_elements;
}
