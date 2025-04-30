#include <string>

std::pair<std::string, std::string> move_num(const std::string& test_str) {
    std::string res;
    std::string dig;
    for (char ele : test_str) {
        if (isdigit(ele)) {
            dig += ele;
        } else {
            res += ele;
        }
    }
    res += dig;
    return {res, dig};
}
