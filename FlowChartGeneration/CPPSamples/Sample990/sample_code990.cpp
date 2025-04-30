#include <set>
#include <string>
#include <algorithm>

int count_distinct_characters(const std::string& str) {
    std::set<char> distinct_chars;
    for (char c : str) {
        distinct_chars.insert(tolower(c));
    }
    return distinct_chars.size();
}
