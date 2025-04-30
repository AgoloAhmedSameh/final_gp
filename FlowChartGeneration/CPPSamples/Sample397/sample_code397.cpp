#include <iostream>
#include <vector>
#include <string>

int sum_of_digits(const std::vector<int>& nums) {
    int sum = 0;
    for (int n : nums) {
        for (char el : std::to_string(n)) {
            if (std::isdigit(el)) {
                sum += el - '0';
            }
        }
    }
    return sum;
}
