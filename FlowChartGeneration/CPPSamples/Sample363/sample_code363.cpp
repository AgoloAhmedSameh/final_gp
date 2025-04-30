#include <string>
using namespace std;

char make_flip(char ch) {
    return (ch == '0') ? '1' : '0';
}

int get_flip_with_starting_character(const string& str, char expected) {
    int flip_count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != expected) {
            flip_count++;
        }
        expected = make_flip(expected);
    }
    return flip_count;
}

int min_flip_to_make_string_alternate(const string& str) {
    return min(get_flip_with_starting_character(str, '0'), get_flip_with_starting_character(str, '1'));
}
