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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) return ans;

        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()) {
            int size = Q.size();

            vector<int> children;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();

                children.push_back(curr->val);
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            ans.push_back(children);
        }
        return ans;
    }
};
