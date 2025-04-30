#include <vector>
#include <queue>
#include <utility>
#include <limits>

class Node {
public:
    int value;
    int list_num;
    int index;
    
    Node(int v, int ln, int idx) : value(v), list_num(ln), index(idx) {}
    
    bool operator<(const Node& other) const {
        return value > other.value; // For a min-heap, we invert the comparison
    }
};

std::pair<int, int> find_minimum_range(const std::vector<std::vector<int>>& lists) {
    int high = std::numeric_limits<int>::min();
    std::pair<int, int> p(0, std::numeric_limits<int>::max());
    std::priority_queue<Node> pq;
    
    for (int i = 0; i < lists.size(); ++i) {
        pq.push(Node(lists[i][0], i, 0));
        high = std::max(high, lists[i][0]);
    }

    while (true) {
        Node top = pq.top();
        pq.pop();
        int low = top.value;
        int i = top.list_num;
        int j = top.index;

        if (high - low < p.second - p.first) {
            p = std::make_pair(low, high);
        }
        
        if (j == lists[i].size() - 1) {
            return p;
        }
        
        pq.push(Node(lists[i][j + 1], i, j + 1));
        high = std::max(high, lists[i][j + 1]);
    }
}
