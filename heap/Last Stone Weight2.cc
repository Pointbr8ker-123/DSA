// array implementation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (!stones.empty()) {
            sort(stones.begin(), stones.end());

            int n = stones.size();

            int y = stones[n-1];
            int x = stones[n-2];
            
            stones.pop_back();
            stones.pop_back();

            if (x != y) stones.push_back(y - x);
        }
        return (stones.empty()) ? 0 : stones[0];
    }
};