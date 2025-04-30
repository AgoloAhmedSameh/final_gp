#include <utility>

std::pair<int, int> parallelogram_perimeter(int b, int h) {
    int perimeter = 2 * (b + h);
    return {perimeter, perimeter}; // Return perimeter as a pair
}
