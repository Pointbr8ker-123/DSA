// This is a C++ implementation of Level-Order Traversal of a binary tree
// this can also be referred to as Pre-Order Traversal of a binary tree.

// In this traversal method, the root node (value) is read first, then the left
// node, and then the right, thereby reading the values in the nodes of the tree 
// level by level.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = nullptr;

// Since we cant go back after we visit each node, and we also can't use one
// pointer to traverse the entire tree, we use a queue to store the values of
// the node (i.e the root) and its children (i.e left and right) at each level 
// before going over to the next node

void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> Q;
    Q.push(root);
    
    while (!Q.empty()) {
        Node* curr = Q.front();
        cout << curr->data << " ";
        if (curr->left) Q.push(curr->left);
        if (curr->right) Q.push(curr->right);
        Q.pop();
    }
    cout << endl;
}


Node* GetNewNode(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    return new_node;
}

Node* Insert(Node* root, int data) {
    if (root == nullptr) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}


int main() {
    root = Insert(root, 10);
    root = Insert(root, 9);
    root = Insert(root, 100);
    root = Insert(root, 123);
    root = Insert(root, 17);
    root = Insert(root, 1);
    root = Insert(root, 45);
    root = Insert(root, 334);

    levelOrder(root);

    return 0;
}