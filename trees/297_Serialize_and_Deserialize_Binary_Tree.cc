#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        queue<TreeNode*> q;
        q.push(root);
        
        string ans = "";
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr) {
                ans += (to_string(curr->val) + ",");
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            } else ans += "null,";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "null") return nullptr;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));