// leetcode 543

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
    // declare a global variable that can be accessible from anywhere so we can
    // update its value in the max_depth function and also return it in the main
    // function.
    int max_d = 0;
private:
    // create a helper function that recursively checks each node in the binary
    // tree and computes the height of the left and right subtree and uses these
    // info to generate the max diameter from that node and updates the "max_d"
    // global variable.
    int max_depth(TreeNode* root) {
        // this is the standard "max_depth of a node" implementation from leetcode
        // 104, but we have the "max_d" update line in there
        if (!root) return 0;

        int l = max_depth(root->left);
        int r = max_depth(root->right);

        // the diameter would be the sum of the heights of the right and left
        // subtrees... this would keep updating as recursion goes on until we 
        // have the maximum diameter of the tree.
        max_d = max(max_d, l + r);

        return max(l, r) + 1; 
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_depth(root);
        return max_d;
    }
};