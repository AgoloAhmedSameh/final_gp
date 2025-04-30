#include <iostream>
#include <string>
using namespace std;

pair<int, int> length_Of_Last_Word(string a) {
    int l = 0;
    string x = a;
    x.erase(0, x.find_first_not_of(" ")); // Trim leading spaces
    x.erase(x.find_last_not_of(" ") + 1); // Trim trailing spaces
    
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == ' ') {
            l = 0;
        } else {
            l++;
        }
    }
    return make_pair(l, l);
}
