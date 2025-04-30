#include <vector>
#include <tuple>

std::tuple<int, int> sum_product(const std::vector<int>& numbers) {
    int sum_value = 0;
    int prod_value = 1;

    for (int n : numbers) {
        sum_value += n;
        prod_value *= n;
    }
    return std::make_tuple(sum_value, prod_value);
}
