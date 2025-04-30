#include <string>
#include <vector>

bool find_substring(const std::vector<std::string>& str1, const std::string& sub_str) {
    for (const auto& s : str1) {
        if (s.find(sub_str) != std::string::npos) {
            return true;
        }
    }
    return false;
}
