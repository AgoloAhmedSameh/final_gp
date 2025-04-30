#include <iostream>
#include <vector>
#include <string>

std::string Strongest_Extension(const std::string& class_name, const std::vector<std::string>& extensions) {
    std::string strong = extensions[0];
    int my_val = 0;

    for (char x : extensions[0]) {
        if (isalpha(x)) {
            if (isupper(x)) my_val++;
            else my_val--;
        }
    }

    for (const auto& s : extensions) {
        int val = 0;
        for (char x : s) {
            if (isalpha(x)) {
                if (isupper(x)) val++;
                else val--;
            }
        }
        if (val > my_val) {
            strong = s;
            my_val = val;
        }
    }

    return class_name + "." + strong;
}
