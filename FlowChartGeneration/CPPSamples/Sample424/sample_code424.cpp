#include <vector>
#include <string>

std::pair<int, int> count_element_in_list(const std::vector<std::string>& list1, const std::string& x) { 
    int ctr = 0; 
    for (size_t i = 0; i < list1.size(); ++i) { 
        if (list1[i].find(x) != std::string::npos) { 
            ctr++; 
        } 
    } 
    return {ctr, 0}; 
}
