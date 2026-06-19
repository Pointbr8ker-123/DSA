#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    unordered_set<char> seen;
    int max_length = 0;

    while (right < s.size()) {
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            left++;
        }

        seen.insert(s[right]);
        max_length = max(max_length, right-left+1);
        right++;
    }
    return max_length;
}
