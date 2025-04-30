#include <tuple>

std::tuple<int> min_of_three(int a, int b, int c) {
    int smallest;
    if ((a <= b) && (a <= c)) {
        smallest = a;
    } else if ((b <= a) && (b <= c)) {
        smallest = b;
    } else {
        smallest = c;
    }
    return std::make_tuple(smallest);
}
