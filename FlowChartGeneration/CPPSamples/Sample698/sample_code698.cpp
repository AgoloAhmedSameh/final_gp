#include <string>

std::string min_Swaps(std::string str1, std::string str2) {
    int count = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            count++;
        }
    }
    if (count % 2 == 0) {
        return std::to_string(count / 2);
    } else {
        return "Not Possible";
    }
}
