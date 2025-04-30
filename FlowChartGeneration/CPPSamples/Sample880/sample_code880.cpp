#include <iostream>
#include <vector>

std::pair<int, int> sum_even_odd(const std::vector<int>& list1) {
    int first_even = -1;
    int first_odd = -1;

    for (int el : list1) {
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

    return {first_even + first_odd, 0};
}
