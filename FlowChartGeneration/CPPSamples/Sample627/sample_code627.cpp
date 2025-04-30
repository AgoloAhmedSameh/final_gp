#include <iostream>
#include <string>
#include <algorithm>

const int MAX = 1000;

std::string replace_spaces(std::string str) {
    str = str.erase(0, str.find_first_not_of(" \n\r\t")) // trim left
               .erase(str.find_last_not_of(" \n\r\t") + 1); // trim right
    int i = str.length();
    int space_count = std::count(str.begin(), str.end(), ' ');
    int new_length = i + space_count * 2;
    if (new_length > MAX) {
        return "-1"; // Return -1 as a string for consistency
    }
    int index = new_length - 1;
    str.resize(new_length);
    for (int f = i - 1; f < new_length - 2; f++) {
        str.push_back('0');
    }
    for (int j = i - 1; j >= 0; j--) {
        if (str[j] == ' ') {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index -= 3;
        } else {
            str[index] = str[j];
            index--;
        }
    }
    return str;
}
