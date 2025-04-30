#include <string>
#include <vector>

std::string file_name_check(const std::string& file_name) {
    std::vector<std::string> suf = {"txt", "exe", "dll"};
    size_t pos = file_name.find('.');
    if (pos == std::string::npos || pos == 0 || pos == file_name.length() - 1) {
        return "No";
    }
    std::string name = file_name.substr(0, pos);
    std::string extension = file_name.substr(pos + 1);

    if (std::find(suf.begin(), suf.end(), extension) == suf.end()) {
        return "No";
    }
    if (!std::isalpha(name[0])) {
        return "No";
    }
    
    int digit_count = 0;
    for (char c : name) {
        if (std::isdigit(c)) {
            digit_count++;
        }
    }

    if (digit_count > 3) {
        return "No";
    }
    return "Yes";
}
