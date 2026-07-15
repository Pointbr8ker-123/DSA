// Leetcode 572

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
    // create a helper function inspired by leetcode 100's solution
    // which compares two binaty trees from thier root nodes to check if 
    // they are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right);
    }

    // this is another helper function that helps put the first helper 
    // function above into use: it checks if the main tree node is null
    // and returns false if it is... otherwise, it uses the isSameTree
    // helper function to check if the tree and the subtree are identical.
    // Finally, it recursively checks each node (and the subsequent substree
    // under the node if any) and compares it to the substree using the first
    // helper function until we find an identical subtree... or not.
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p) return false;
        if (isSameTree(p, q)) return true;
        return helper(p->left, q) || helper(p->right, q);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot);
    }
};