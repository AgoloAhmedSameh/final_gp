#include <vector>

int find_gcd(int x, int y) {
    while (y) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

std::pair<int, int> get_gcd(const std::vector<int>& l) {
    int num1 = l[0];
    int num2 = l[1];
    int gcd = find_gcd(num1, num2);
    for (size_t i = 2; i < l.size(); i++) {
        gcd = find_gcd(gcd, l[i]);
    }
    return {gcd, gcd};
}
