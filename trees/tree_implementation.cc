// Implementing A Binary Search Tree from scratch

#include <bits/stdc++.h>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* root = nullptr;

BstNode* GetNewNode(int data) {
    BstNode* new_node = new BstNode();
    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    return new_node;
}

BstNode* Insert(BstNode* root, int data) {
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

bool Search(BstNode* root, int data) {
    if (root == nullptr) return false;
    if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
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

    cout << "Input your data" <<  endl;
    int data;
    cin >> data;
    if (Search(root, data)) cout << "Found\n";
    else cout << "Not Found\n";

    return 0;
}