#include <iostream>
#include <string>

int digits(int n) {
    int product = 1;
    int odd_count = 0;
    std::string str_n = std::to_string(n);
    for (char digit : str_n) {
        int int_digit = digit - '0';
        if (int_digit % 2 == 1) {
            product = product * int_digit;
            odd_count++;
        }
    }
    if (odd_count == 0) {
        return 0;
    } else {
        return product;
    }
}
