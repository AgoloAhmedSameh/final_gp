#include <string>

int how_many_times(const std::string& str, const std::string& substr) {
    int times = 0;

    for (size_t i = 0; i <= str.length() - substr.length(); ++i) {
        if (str.substr(i, substr.length()) == substr) {
            times++;
        }
    }

    return times;
}
