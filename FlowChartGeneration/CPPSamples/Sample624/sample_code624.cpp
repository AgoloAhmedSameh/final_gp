#include <vector>

std::pair<std::vector<int>, std::vector<int>> swap_List(std::vector<int> newList) {
    int size = newList.size();
    int temp = newList[0];
    newList[0] = newList[size - 1];
    newList[size - 1] = temp;
    return {newList, newList};
}
