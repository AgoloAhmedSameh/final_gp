#include <iostream>
#include <set>

std::pair<int, std::string> amicable_numbers_sum(int limit) {
    if (typeid(limit) != typeid(int)) {
        return {0, "Input is not an integer!"};
    }
    if (limit < 1) {
        return {0, "Input must be bigger than 0!"};
    }
    std::set<int> amicables;
    for (int num = 2; num <= limit; num++) {
        if (amicables.find(num) != amicables.end()) {
            continue;
        }
        
        int sum_fact = 0;
        for (int fact = 1; fact < num; fact++) {
            if (num % fact == 0) {
                sum_fact += fact;
            }
        }
        
        int sum_fact2 = 0;
        for (int fact = 1; fact < sum_fact; fact++) {
            if (sum_fact % fact == 0) {
                sum_fact2 += fact;
            }
        }
        
        if (num == sum_fact2 && num != sum_fact) {
            amicables.insert(num);
            amicables.insert(sum_fact2);
        }
    }
    
    int total_sum = 0;
    for (int num : amicables) {
        total_sum += num;
    }
    
    return {total_sum, ""};
}
