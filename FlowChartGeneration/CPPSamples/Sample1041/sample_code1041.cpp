#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int fruit_distribution(const std::string& s, int n) {
    std::vector<int> lis;
    std::istringstream iss(s);
    std::string i;
    while (iss >> i) {
        if (std::all_of(i.begin(), i.end(), ::isdigit)) {
            lis.push_back(std::stoi(i));
        }
    }
    int sum = 0;
    for (int num : lis) {
        sum += num;
    }
    return n - sum;
}
