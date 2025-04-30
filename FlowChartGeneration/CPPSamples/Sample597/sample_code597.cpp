#include <iostream>
#include <cmath>

bool armstrong_number(int number) {
    int sum = 0;
    int times = 0;
    int temp = number;

    while (temp > 0) {
        times++;
        temp /= 10;
    }

    temp = number;
    while (temp > 0) {
        int reminder = temp % 10;
        sum += pow(reminder, times);
        temp /= 10;
    }

    return number == sum;
}
