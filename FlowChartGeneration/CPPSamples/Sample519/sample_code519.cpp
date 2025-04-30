#include <vector>
using namespace std;

int find_lcm(int num1, int num2) {
    int num, den;
    if(num1 > num2) {
        num = num1;
        den = num2;
    } else {
        num = num2;
        den = num1;
    }
    int rem = num % den;
    while (rem != 0) {
        num = den;
        den = rem;
        rem = num % den;
    }
    int gcd = den;
    int lcm = (num1 * num2) / gcd;
    return lcm;
}

pair<int, int> get_lcm(const vector<int>& l) {
    int num1 = l[0];
    int num2 = l[1];
    int lcm = find_lcm(num1, num2);
    for(size_t i = 2; i < l.size(); ++i) {
        lcm = find_lcm(lcm, l[i]);
    }
    return {lcm, lcm}; // Adjusted return type for consistency
}
