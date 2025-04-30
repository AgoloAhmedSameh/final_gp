#include <iostream>
#include <tuple>

std::tuple<int, int> profit_amount(int actual_cost, int sale_amount) {
    if (actual_cost > sale_amount) {
        int amount = actual_cost - sale_amount;
        return std::make_tuple(amount, 0);
    } else {
        return std::make_tuple(0, 1); // Using 1 to indicate None
    }
}
