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

class Solution {
private:
    unordered_map<int, int> _map;
    int preorder_idx;

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = _map[root_val];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        _map.clear();
        for (int i = 0; i < inorder.size(); i++) {
            _map[inorder[i]] = i;
        }
        preorder_idx = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};