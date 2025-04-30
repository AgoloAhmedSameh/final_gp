#include <tuple>

std::tuple<int, int> perimeter_triangle(int a, int b, int c) {
    int perimeter = a + b + c;
    return std::make_tuple(perimeter);
}
