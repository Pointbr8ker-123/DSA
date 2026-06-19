#include <bits/stdc++.h>
using namespace std;

string longest_common_prefix(vector<string>& strs) {
    string result = "";
    for (int i = 0; i < strs[0].size(); i++) {
        for (string word : strs) {
            if (i == word.size() || word[i] != strs[0][i]) {
                return result;
            }
        }
        result += strs[0][i];
    }
    return result;
}

int main() {
    vector<string> strs = {"flow", "flower", "flowing"};
    string result = longest_common_prefix(strs);

    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}