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
    vector<vector<int>> findLeaves(TreeNode* root) {
        // create a vector of vectors container to house the final answer
        vector<vector<int>> res;

        // use a dummy node as the parent of the root node and this will 
        // eventually help with out tree traversal via DFS
        TreeNode* prev = new TreeNode(0, root, nullptr);

        // NB: prev-left initially is the root node and the while look keeps
        // running till we've exhausted all the leaf nodes in the tree
        while (prev->left) {
            vector<int> t;
            dfs(prev->left, prev, t);
            res.push_back(t);
        }
        return res;
    }

private:
    void dfs(TreeNode* root, TreeNode* prev, vector<int>& t) {
        if (!root) return;
        // i.e if the node is a leaf node
        if (!root->left && !root->right) {
            // add its value to the vector (that will later be joined with
            // the final answer vector)
            t.push_back(root->val);
            // if the current "root" (i.e the leaf node we just pushed its value)
            // is equal to the left child of its parent, set it to nullptr, thereby
            // deleting it... or if its the right child instead, set the right child
            // to nullptr
            if (prev->left == root) 
                prev->left = nullptr;
            else prev->right = nullptr;
        } 
        // go down the left side first, then each step back up, we go down the right
        // path before we unwind fully
        dfs(root->left, root, t);
        dfs(root->right, root, t);
    }
};