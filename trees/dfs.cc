#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Pre-Order Traversal
void dfsRecursive(Node* root) {
    // Base case: if the node is null, return
    if (root == nullptr) {
        return;
    }

    // Process the current node
    std::cout << root->data << " ";

    // Recur on the left subtree
    dfsRecursive(root->left);

    // Recur on the right subtree
    dfsRecursive(root->right);
}

// In-Order Traversal:
// dfsRecursive(root->left);        // 1. Left
// std::cout << root->data << " "; // 2. Root
// dfsRecursive(root->right);       // 3. Right

// Post-Order Traversal:
// dfsRecursive(root->left);        // 1. Left
// dfsRecursive(root->right);       // 2. Right
// std::cout << root->data << " "; // 3. Root

