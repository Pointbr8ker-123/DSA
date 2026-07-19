#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode* tn;

class Solution {
private:
    vector<tn> findAncestors(tn root, tn target_node) {
        vector<tn> ancestors;
        while(root && root != target_node) {
            ancestors.push_back(root);
            if (target_node->val > root->val) root = root->right; 
            else root = root->left;
        }
        return ancestors;
    }
    
public:
    TreeNode* lowestCommonAncestor(tn root, tn p, tn q) {
        vector<tn> P = findAncestors(root, p);
        vector<tn> Q = findAncestors(root, q);

        int size = max(P.size(), Q.size());
        tn ans;
        int min_anc = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (P[i]->val == Q[i]->val && P[i]->val < min_anc) {
                ans = P[i];
                min_anc = P[i]->val;
            }
        }
        return ans;
    }
};