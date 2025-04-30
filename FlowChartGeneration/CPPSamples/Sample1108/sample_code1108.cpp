#include <string>
#include <cctype>

bool check_if_last_char_is_a_letter(const std::string& txt) {
    std::string::size_type pos = txt.find_last_of(' ');
    std::string check = (pos == std::string::npos) ? txt : txt.substr(pos + 1);
    return (check.length() == 1 && std::islower(check[0]));
}
