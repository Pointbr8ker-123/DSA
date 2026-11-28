#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Check if endWord exists in the wordList... if it doesnt, then we'd never find it
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        // Add the beginWord into the wordList so we can use if for BFS
        wordList.push_back(beginWord);

        // Create an adjacency List
        unordered_map<string, vector<string>> adjList;

        // Populate the adjacency list using pattern matching
        for (const string& word : wordList) {
            for (int i{}; i < word.size(); i++) {
                string pattern { word };
                pattern[i] = '*';
                adjList[pattern].push_back(word); // match words to matching patterns (i.e difference of one character)
            }
        }

        // Create a hashset to track visited words
        unordered_set<string> visited;
        visited.insert(beginWord);

        queue<string> q;
        q.push(beginWord);

        int ans { 1 };
        while(!q.empty()) {
            int n = q.size();
            for (int i {}; i < n; i++) {
                string curr { q.front() };
                q.pop();

                if (curr == endWord) return ans;

                for (int j {}; j < curr.size(); j++) {
                    string pattern { curr };
                    pattern[j] = '*';

                    for (const string& word : adjList[pattern]) {
                        if (visited.find(word) == visited.end()) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};

// ------------------------------------ NORTH STAR ---------------------------------------------------
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         const int L = beginWord.size();
//         auto enc = [](const string& s) {
//             uint64_t c = 0;
//             for (char ch : s) c = c << 5 | (uint64_t)(ch - 'a' + 1);  // 5 bits/char
//             return c;
//         };

//         int cap = 2; while (cap < 2 * ((int)wordList.size() + 1)) cap <<= 1;
//         const int shift = 64 - __builtin_ctz(cap);
//         vector<uint64_t> key(cap, 0);
//         vector<uint8_t> side(cap, 0);  // 0 = unvisited, 1/2 = reached from begin/end
//         auto slot = [&](uint64_t k) -> uint32_t {
//             uint32_t h = (k * 0x9E3779B97F4A7C15ull) >> shift;
//             while (key[h] && key[h] != k) h = (h + 1) & (cap - 1);
//             return h;
//         };
//         for (auto& w : wordList) { uint64_t c = enc(w); key[slot(c)] = c; }

//         uint64_t b = enc(beginWord), e = enc(endWord);
//         uint32_t es = slot(e);
//         if (!key[es]) return 0;
//         uint32_t bs = slot(b); key[bs] = b; side[bs] = 1; side[es] = 2;

//         vector<uint64_t> A{b}, B{e}, next;
//         uint8_t sa = 1, sb = 2;
//         for (int len = 2; !A.empty() && !B.empty(); len++) {
//             if (A.size() > B.size()) { swap(A, B); swap(sa, sb); }  // grow the smaller side
//             next.clear();
//             for (uint64_t u : A)
//                 for (int i = 0; i < 5 * L; i += 5) {
//                     uint64_t orig = (u >> i) & 31, base = u & ~(31ull << i);
//                     for (uint64_t c = 1; c <= 26; c++) {
//                         if (c == orig) continue;
//                         uint32_t h = slot(base | c << i);
//                         if (!key[h]) continue;
//                         if (side[h] == sb) return len;      // frontiers met
//                         if (!side[h]) { side[h] = sa; next.push_back(key[h]); }
//                     }
//                 }
//             swap(A, next);
//         }
//         return 0;
//     }
// };