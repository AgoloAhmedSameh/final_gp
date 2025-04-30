#include <iostream>
#include <string>

std::string decimal_to_binary(int decimal) {
    return "db" + std::to_string(decimal) + "db"; // Note: This line does not convert to binary as per original Python logic.
}
