#include <iostream>

std::pair<int, int> find_Min_Sum(int num) {
    int sum = 0;
    int i = 2;
    while (i * i <= num) {
        while (num % i == 0) {
            sum += i;
            num /= i;
        }
        i += 1;
    }
    sum += num;
    return {sum, 0}; // Assuming you want to return a second value as 0
}

int main() {
    int num = 100; // Example input
    auto result = find_Min_Sum(num);
    std::cout << "Sum: " << result.first << std::endl;
    return 0;
}
