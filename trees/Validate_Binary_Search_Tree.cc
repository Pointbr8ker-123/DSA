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

typedef long long ll;
class Solution {
private:
    bool valid(TreeNode* root, ll mini, ll maxi) {
        if (!root) return true;
        if (!(root->val < maxi && root->val > mini)) return false;
        return valid(root->left, mini, root->val) && 
               valid(root->right, root->val, maxi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};