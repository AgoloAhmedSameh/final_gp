#include <iostream>
using namespace std;

pair<int, int> max_of_three(int num1, int num2, int num3) {
    int lnum;
    if ((num1 >= num2) && (num1 >= num3)) {
        lnum = num1;
    } else if ((num2 >= num1) && (num2 >= num3)) {
        lnum = num2;
    } else {
        lnum = num3;
    }
    return make_pair(lnum, 0); // Assuming the second return value is not needed.
}
