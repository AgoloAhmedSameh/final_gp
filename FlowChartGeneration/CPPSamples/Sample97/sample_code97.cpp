#include <vector>

std::pair<double, double> multiply_num(const std::vector<int>& numbers) {  
    double total = 1;  
    for (int x : numbers) {  
        total *= x;  
    }  
    return {total / numbers.size(), total};  
}
