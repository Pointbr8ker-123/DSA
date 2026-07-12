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
    pair<bool, int> check(TreeNode* root) {
        if (!root) return {true, 0};

        auto[isLeftBalanced, leftHeight] = check(root->left);
        auto[isRightBalanced, rightHeight] = check(root->right);

        bool isBalanced = isLeftBalanced && isRightBalanced &&
                            abs(leftHeight - rightHeight) <= 1;

        return {isBalanced, max(leftHeight, rightHeight) + 1};
    }

public:
    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }
};