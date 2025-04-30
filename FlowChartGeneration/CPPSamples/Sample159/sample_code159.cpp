#include <iostream>
#include <tuple>

std::tuple<std::string, int, std::string, int> solution(int a, int b, int n) {
    int i = 0;
    while (i * a <= n) {
        if ((n - (i * a)) % b == 0) {
            return std::make_tuple("x = ", i, ", y = ", (n - (i * a)) / b);
        }
        i = i + 1;
    }
    return std::make_tuple("No solution");
}
