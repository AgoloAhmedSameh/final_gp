#include <utility>

std::pair<int, int> rectangle_perimeter(int l, int b) {
    int perimeter = 2 * (l + b);
    return {perimeter, perimeter}; // Assuming you want to return the perimeter twice as in the original function
}
