#include <bits/stdc++.h>
using namespace std;

// BFS
class Solution {
private:
    // This is the helper function that iterates through the values of a 
    // 'parent' and gets out the 8 possible outcomes/permutations/children
    // for any decision that would be made on said 'parent'.
    vector<string> children(const string &parent) {
        vector<string> res;

        for (int i = 0; i < 4; i++) {
            string inc = parent;
            string dec = parent;

            inc[i] = (parent[i] == '9') ? 0 : parent[i] + 1;
            dec[i] = (parent[i] == '0') ? 9 : parent[i] - 1;

            res.push_back(inc);
            res.push_back(dec);
        }
        return res;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        // convert the 'deadends' vector to hashset so that we can search for
        // values that are in deadends in O(1) time complexity
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());

        // create a hashset 'visited' to track the elements/children that we
        // have visited before
        unordered_set<string> visited;

        // check if the starting value "0000" is in the deadends set... if it 
        // is, then there's no need to continue with other operations as it
        // would be impossible to carry on with the search since the very first
        // value is already a deadend
        if (deadendsSet.count("0000")) {
            return -1;
        }

        // create a queue for the Breadth-First-Search (BFS)
        queue<pair<string, int>> bfs;

        // since we have already checked "0000" and its not a deadend, and its
        // obviously the starting value, insert it into the 'visited' hashset
        // and into the queue.
        bfs.push({"0000", 0});
        visited.insert("0000");

        // iterate (using a while loop) through the queue to check if the current
        // value is the target, if it is, we return the shortest num of steps it
        // took to get to that value (i.e without meeting a deadend), else we go
        // through its children to look for a match with the target
        while (!bfs.empty()) {
            auto [curr, steps] = bfs.front();
            bfs.pop();

            if (curr == target) {
                return steps;
            }

            for (string child : children(curr)) {
                if (!deadendsSet.count(child) && !visited.count(child)) {
                    visited.insert(child);
                    bfs.push({child, steps + 1});
                }
            }
        }
        return -1;
    }
};