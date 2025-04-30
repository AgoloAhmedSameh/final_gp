#include <iostream>
using namespace std;

pair<int, int> count_Fac(int n) {  
    int m = n; 
    int count = 0; 
    int i = 2; 
    while ((i * i) <= m) { 
        int total = 0; 
        while (n % i == 0) { 
            n /= i; 
            total += 1; 
        } 
        int temp = 0; 
        int j = 1; 
        while ((temp + j) <= total) { 
            temp += j; 
            count += 1; 
            j += 1; 
        } 
        i += 1; 
    } 
    if (n != 1) { 
        count += 1; 
    } 
    return make_pair(count, 0); // Returning 0 as the second value as the original Python function returns two values.
}
