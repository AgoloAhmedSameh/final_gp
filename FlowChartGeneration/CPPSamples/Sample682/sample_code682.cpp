#include <iostream>
using namespace std;

bool sum_Square(int n) {
    int i = 1;
    while (i * i <= n) {
        int j = 1;
        while (j * j <= n) {
            if (i * i + j * j == n) {
                return true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return false;
}
