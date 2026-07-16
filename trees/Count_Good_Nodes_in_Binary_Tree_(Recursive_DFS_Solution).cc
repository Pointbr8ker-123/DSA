// Leetcode 1448

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
    int dfs(TreeNode* root, int max_so_far) {
        if (!root) return 0;

        int good = 0;
        if (root->val >= max_so_far) good = 1;

        max_so_far = max(max_so_far, root->val);
        
        return good + dfs(root->left, max_so_far)
                    + dfs(root->right, max_so_far);
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};