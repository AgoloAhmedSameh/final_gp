#include <vector>
#include <algorithm>

bool is_palindrome(int n) {
    int divisor = 1;
    while (n / divisor >= 10) {
        divisor *= 10;
    }
    while (n != 0) {
        int leading = n / divisor;
        int trailing = n % 10;
        if (leading != trailing) {
            return false;
        }
        n = (n % divisor) / 10;
        divisor = divisor / 100;
    }
    return true;
}

int largest_palindrome(std::vector<int>& A, int n) {
    std::sort(A.begin(), A.end());
    for (int i = n - 1; i >= 0; i--) {
        if (is_palindrome(A[i])) {
            return A[i];
        }
    }
    return -1;
}
