#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int n = s.size();
    int ans = 0;
     
    // Odd-length palindrome
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
    }

    for (int i = 0; i < n; i++) {
        int l = i, r = i+1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
    }
    
    return ans;
}

int main() {
    string s = "caba";
    int out = countSubstrings(s);
    cout << out << endl;

    return 0;
}