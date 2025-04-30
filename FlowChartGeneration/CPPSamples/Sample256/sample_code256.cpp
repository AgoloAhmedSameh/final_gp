#include <utility>

std::pair<int, int> swap_numbers(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    return std::make_pair(a, b);
}
