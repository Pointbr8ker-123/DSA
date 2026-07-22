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
    priority_queue<int> pq;
private:
    void preOrder(TreeNode* root, int k) {
        if (!root) return;
        pq.push(root->val);
        if (pq.size() > k) pq.pop();
        preOrder(root->left, k);
        preOrder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        preOrder(root, k);
        return pq.top();
    }
};