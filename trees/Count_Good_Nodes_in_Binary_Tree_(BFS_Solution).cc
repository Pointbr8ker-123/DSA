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
public:
    int goodNodes(TreeNode* root) {
        int good = 0;
        if (!root) return good;

        good++;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()) {
            int size = q.size(); 

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                
                if (curr->left) {
                    int max_val_left = q.front().second;
                    if (curr->left->val >= max_val_left) {
                        good++;
                        max_val_left = max(curr->left->val, max_val_left);
                    }
                    q.push({curr->left, max_val_left});
                }
                
                if (curr->right) {
                    int max_val_right = q.front().second;
                    if (curr->right->val >= max_val_right) {
                        good++;
                        max_val_right = max(curr->right->val, max_val_right);
                    }
                    q.push({curr->right, max_val_right});
                } 
                q.pop();
            }
        }
        return good;
    }
};