#include <vector>
#include <algorithm>

bool move_one_ball(std::vector<int>& arr) {
    if (arr.empty()) {
        return true;
    }
    
    std::vector<int> sorted_array = arr;
    std::sort(sorted_array.begin(), sorted_array.end());
    std::vector<int> my_arr;
    
    int min_value = *std::min_element(arr.begin(), arr.end());
    int min_index = std::find(arr.begin(), arr.end(), min_value) - arr.begin();
    
    my_arr.insert(my_arr.end(), arr.begin() + min_index, arr.end());
    my_arr.insert(my_arr.end(), arr.begin(), arr.begin() + min_index);
    
    for (size_t i = 0; i < arr.size(); ++i) {
        if (my_arr[i] != sorted_array[i]) {
            return false;
        }
    }
    return true;
}
