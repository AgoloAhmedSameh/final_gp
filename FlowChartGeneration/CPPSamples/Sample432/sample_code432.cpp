#include <iostream>
#include <vector>
#include <algorithm>

std::string check_greater(std::vector<int> arr, int number) {
    std::sort(arr.begin(), arr.end());
    if (number > arr.back()) {
        return "Yes, the entered number is greater than those in the array";
    } else {
        return "No, entered number is less than those in the array";
    }
}
