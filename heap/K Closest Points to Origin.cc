#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> squared;
        for (int i = 0; i < points.size(); i++) {
            int square = pow(points[i][0], 2) + pow(points[i][1], 2);
            squared.push_back({square, i});
        }

        priority_queue<pair<int, int>> max_heap;
        for (pair<int, int> p : squared) {
            max_heap.push(p);

            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            vector<int> val = points[max_heap.top().second];
            ans.push_back(val);
            max_heap.pop();
        }
        return ans;
    }
};