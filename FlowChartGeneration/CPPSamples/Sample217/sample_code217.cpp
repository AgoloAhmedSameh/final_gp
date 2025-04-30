#include <iostream>
#include <algorithm>
#include <numeric>

std::pair<int, int> min_Operations(int A, int B) {
    if (A > B) {
        std::swap(A, B);
    }
    B = B / std::gcd(A, B);
    return {B - 1, 0}; // Since there was no second return value in the original Python code
}
