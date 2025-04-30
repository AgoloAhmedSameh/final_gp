#include <vector>
#include <algorithm>

struct Item {
    double price;
    // other attributes
};

std::vector<Item> expensive_items(const std::vector<Item>& items, size_t n) {
    std::vector<Item> expensive_items = items;
    std::partial_sort(expensive_items.begin(), expensive_items.begin() + n, expensive_items.end(), [](const Item& a, const Item& b) {
        return a.price > b.price;
    });
    expensive_items.resize(n);
    return expensive_items;
}
