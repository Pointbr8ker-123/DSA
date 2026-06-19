#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string pre = strs[0];
    int pre_len = pre.size();

    for(int i = 1; i < strs.size(); i++) {
        string s = strs[i];
        while(pre_len > s.size() || pre != s.substr(0, pre_len)) {
            pre_len--;
            if (pre_len == 0) return "";
            pre = pre.substr(0, pre_len);
        }
    }
    return pre;
}

int main() {
    vector<string> strs = {"dog","racecar","car"};
    string output = longestCommonPrefix(strs);
    cout << output << endl;

    return 0;
}