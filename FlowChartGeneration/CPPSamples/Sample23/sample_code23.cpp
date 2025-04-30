#include <iostream>
#include <cmath>

int binary_to_decimal(int binary) {
    int decimal = 0, i = 0;
    while (binary != 0) {
        int dec = binary % 10;
        decimal = decimal + dec * pow(2, i);
        binary = binary / 10;
        i++;
    }
    return decimal;
}
