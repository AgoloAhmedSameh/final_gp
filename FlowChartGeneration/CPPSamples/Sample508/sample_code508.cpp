#include <iostream>
using namespace std;

pair<int, int> average_Odd(int n) {
    if (n % 2 == 0) {
        cout << "Invalid Input" << endl;
        return make_pair(-1, -1);
    }
    int sm = 0;
    int count = 0;
    while (n >= 1) {
        count = count + 1;
        sm = sm + n;
        n = n - 2;
    }
    return make_pair(sm / count, count);
}
