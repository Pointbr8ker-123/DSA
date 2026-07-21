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
    vector<int> get_leafs(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            res.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return res;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> leafs = get_leafs(root);
        sort(leafs.begin(), leafs.end());
        return leafs[k-1];
    }
};