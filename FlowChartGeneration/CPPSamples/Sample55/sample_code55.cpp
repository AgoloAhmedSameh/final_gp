#include <iostream>
using namespace std;

int rev(int num) {
    int rev_num = 0;
    while (num > 0) {
        rev_num = (rev_num * 10 + num % 10);
        num = num / 10;
    }
    return rev_num;
}

bool check(int n) {
    return (2 * rev(n) == n + 1);
}
