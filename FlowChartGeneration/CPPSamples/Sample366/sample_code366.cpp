#include <algorithm>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int get_height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return std::max(get_height(root->left), get_height(root->right)) + 1;
}

bool is_tree_balanced(Node* root) {
    if (root == nullptr) {
        return true;
    }
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    if (std::abs(lh - rh) <= 1 && is_tree_balanced(root->left) && is_tree_balanced(root->right)) {
        return true;
    }
    return false;
}
