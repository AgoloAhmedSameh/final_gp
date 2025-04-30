#include <iostream>

int catalan_number(int num) {
    if (num <= 1) {
        return 1;
    }
    int res_num = 0;
    for (int i = 0; i < num; i++) {
        res_num += catalan_number(i) * catalan_number(num - i - 1);
    }
    return res_num;
}
