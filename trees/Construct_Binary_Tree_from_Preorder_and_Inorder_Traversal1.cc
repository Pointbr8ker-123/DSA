#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Sub-Optimal solution... worst case, O(n^2)

class Solution {
private:
    TreeNode* build(deque<int>& preorder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int root_val = preorder.front(); preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), root_val);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(root_val);
            vector<int> left_in(inorder.begin(), inorder.begin() + idx);
            vector<int> right_in(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preorder, left_in);
            root->right = build(preorder, right_in);

            return root;
        }
        return nullptr;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderDeque(preorder.begin(), preorder.end());
        return build(preorderDeque, inorder);
    }
};