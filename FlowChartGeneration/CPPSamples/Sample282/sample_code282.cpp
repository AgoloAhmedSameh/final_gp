#include <iostream>

bool validate(int n) {
    for (int i = 0; i < 10; i++) {
        int temp = n;
        int count = 0;
        while (temp) {
            if (temp % 10 == i) {
                count++;
            }
            if (count > i) {
                return false;
            }
            temp /= 10;
        }
    }
    return true;
}
