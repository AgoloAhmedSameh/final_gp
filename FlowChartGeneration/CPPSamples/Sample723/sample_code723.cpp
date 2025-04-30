#include <iostream>
#include <cmath>
#include <string>

int power_base_sum(int base, int power) {
    long long result = pow(base, power);
    std::string result_str = std::to_string(result);
    int sum = 0;
    for (char i : result_str) {
        sum += i - '0';
    }
    return sum;
}
