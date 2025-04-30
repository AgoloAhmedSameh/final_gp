#include <cmath>

int count_Num(int n) { 
    if (n == 1) { 
        return 1; 
    } 
    int count = pow(2, n - 2); 
    return count; 
}
