#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> track;
    unordered_map<char, char> u_map = {{'{', '}'}, {'[', ']'}, {'(', ')'}};

    for (char c : s) {
        if (u_map.find(c) == u_map.end()) {
            track.push(c);
        } else if (!track.empty() && u_map[c] == track.top()) {
            track.pop();
        } else {
            return false;
        }
    }
    return track.empty();
}