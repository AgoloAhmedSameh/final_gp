#include <vector>
#include <iostream>

std::pair<int, int> mul_even_odd(const std::vector<int>& list1) {
    int first_even = -1;
    int first_odd = -1;

    for (const auto& el : list1) {
        if (el % 2 == 0 && first_even == -1) {
            first_even = el;
        }
        if (el % 2 != 0 && first_odd == -1) {
            first_odd = el;
        }
        if (first_even != -1 && first_odd != -1) {
            break;
        }
    }
    
    return std::make_pair(first_even * first_odd, 0);
}
