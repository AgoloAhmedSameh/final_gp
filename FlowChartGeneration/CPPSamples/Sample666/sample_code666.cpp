#include <string>
#include <vector>

int Check_Vow(const std::string& str, const std::string& vowels) {
    std::vector<char> final;
    for (char each : str) {
        if (vowels.find(each) != std::string::npos) {
            final.push_back(each);
        }
    }
    return final.size();
}
