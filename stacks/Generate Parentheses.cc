#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;

        backtrack(0, 0, n, curr, res);
        return res;
    }

private:
    void backtrack(int openN, int closeN, int n, string& curr, vector<string>& ans) {
        if (openN == n && closeN == n) {
            ans.push_back(curr);
            return;
        }

        if (openN < n) {
            curr.push_back('(');
            backtrack(openN + 1, closeN, n, curr, ans);
            curr.pop_back();
        }

        if (closeN < openN) {
            curr.push_back(')');
            backtrack(openN, closeN + 1, n, curr, ans);
            curr.pop_back();
        }
    }
};