#include <string>

int hex_key(const std::string& num) {
    const std::string primes = "2357BD";
    int total = 0;
    for (size_t i = 0; i < num.length(); ++i) {
        if (primes.find(num[i]) != std::string::npos) {
            total += 1;
        }
    }
    return total;
}
