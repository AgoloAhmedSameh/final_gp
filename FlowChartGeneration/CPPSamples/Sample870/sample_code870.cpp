#include <string>

bool are_Rotations(const std::string& string1, const std::string& string2) {
    size_t size1 = string1.size();
    size_t size2 = string2.size();

    if (size1 != size2) {
        return false;
    }

    std::string temp = string1 + string1;

    return temp.find(string2) != std::string::npos;
}
