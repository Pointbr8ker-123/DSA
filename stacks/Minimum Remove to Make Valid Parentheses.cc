#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> track;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                track.push(i);
            } else if (s[i] == ')') {
                if (track.empty()) {
                    s[i] = '#';
                } else {
                    track.pop();
                }
            }
        }

        while(!track.empty()) {
            s[track.top()] = '#';
            track.pop();
        }

        string ans = "";
        for (char c : s) {
            if (c != '#') {
                ans += c;
            }
        }

        return ans;
    }
};