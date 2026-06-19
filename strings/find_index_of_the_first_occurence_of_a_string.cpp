#include <iostream>
#include <algorithm>
using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.size(); i++) {
        string word = haystack.substr(i, needle.size());
        if (word == needle) return i;
    }
    return -1;
}

int main() {
    string haystack = "leetcode", needle = "leeto";
    int index = strStr(haystack, needle);

    cout << index << endl;
    return 0;
}