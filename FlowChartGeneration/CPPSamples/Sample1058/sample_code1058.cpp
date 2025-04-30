#include <string>
#include <vector>
#include <numeric>

std::string solve(int N) {
    int sum = 0;
    for (char digit : std::to_string(N)) {
        sum += digit - '0';
    }
    return std::bitset<32>(sum).to_string().substr(std::bitset<32>(sum).to_string().find('1'));
}
