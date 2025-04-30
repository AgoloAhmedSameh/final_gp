#include <vector>
#include <iostream>

std::pair<int, int> diff_even_odd(const std::vector<int>& list1) {
    int first_even = -1;
    int first_odd = -1;

    for (int el : list1) {
        if (first_even == -1 && el % 2 == 0) {
            first_even = el;
        }
        if (first_odd == -1 && el % 2 != 0) {
            first_odd = el;
        }
        if (first_even != -1 && first_odd != -1) {
            break;
        }
    }

    return {first_even - first_odd, 0}; // Returning second value as a placeholder
}
