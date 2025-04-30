#include <iostream>
#include <string>
#include <vector>

const int NO_OF_CHARS = 256;

std::vector<char> str_to_list(const std::string& str) {
    std::vector<char> temp;
    for (char x : str) {
        temp.push_back(x);
    }
    return temp;
}

std::string lst_to_string(const std::vector<char>& list) {
    return std::string(list.begin(), list.end());
}

int* get_char_count_array(const std::string& str) {
    int* count = new int[NO_OF_CHARS] {0}; 
    for (char i : str) {
        count[static_cast<int>(i)]++;
    }
    return count;
}

std::string remove_dirty_chars(const std::string& string, const std::string& second_string) {
    int* count = get_char_count_array(second_string);
    int ip_ind = 0;
    int res_ind = 0;
    std::string temp;
    std::vector<char> str_list = str_to_list(string);
    
    while (ip_ind != str_list.size()) {
        temp = str_list[ip_ind];
        if (count[static_cast<int>(temp[0])] == 0) {
            str_list[res_ind] = str_list[ip_ind];
            res_ind++;
        }
        ip_ind++;
    }
    delete[] count;
    return lst_to_string(std::vector<char>(str_list.begin(), str_list.begin() + res_ind));
}
