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

// Optimal solution:
// Time Complexity: O(k)
// Space Complexity: O(1)

// Algorithm:
// Use Inorder traversal (which traverses a BST in sorted order from smallest to largest)
// to traverse the BST... Since we are traversing in sorted order, we only have to traverse
// till the kth element from minimum

// Set a counter that keeps updating and keeps the traversal going until the kth element
// then return the value of this kth smallest node
class Solution {
private:
    int count = 0;
    int ans = 0;

    void inOrder(TreeNode* root, int k) {
        if (!root) return;

        inOrder(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return;
        }
        inOrder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};