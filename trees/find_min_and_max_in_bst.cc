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
    new_node->left = nullptr;
    new_node->right = nullptr;
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

int FindMinRecur(BstNode* root) {
    if (root == nullptr) {
        cout << "The tree is empty\n";
        return -1;
    } else if (root->left == nullptr) {
        return root->data;
    } else {
        return FindMinRecur(root->left);
    }
}

int FindMinIter(BstNode* root) {
    if (root == nullptr) {
        cout << "The tree is empty\n";
        return -1;
    }

    while(root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int FindMaxRecur(BstNode* root) {
    if (root == nullptr) {
        cout << "The tree is empty\n";
        return -1;
    } else if (root->right == nullptr) {
        return root->data;
    } else {
        return FindMaxRecur(root->right);
    }
}

int FindMaxIter(BstNode* root) {
    if (root == nullptr) {
        cout << "The tree is empty\n";
        return -1;
    }

    while(root->right != nullptr) {
        root = root->right;
    }
    return root->data;
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

    int min_val1 = FindMinIter(root);
    cout << min_val1 << endl;

    int min_val2 = FindMinRecur(root);
    cout << min_val2 << endl;

    int max_val1 = FindMaxIter(root);
    cout << max_val1 << endl;

    int max_val2 = FindMaxRecur(root);
    cout << max_val2 << endl;

    return 0;
}