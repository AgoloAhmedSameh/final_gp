#include <iostream>
#include <string>

bool simplify(std::string x, std::string n) {
    size_t pos1 = x.find("/");
    size_t pos2 = n.find("/");
    
    int a = std::stoi(x.substr(0, pos1));
    int b = std::stoi(x.substr(pos1 + 1));
    int c = std::stoi(n.substr(0, pos2));
    int d = std::stoi(n.substr(pos2 + 1));
    
    int numerator = a * c;
    int denom = b * d;
    
    return (numerator / denom) == (int)(numerator / denom);
}
