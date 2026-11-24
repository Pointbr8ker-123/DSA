#include <bits/stdc++.h>
using namespace std;

// Using Kahn's Algorithm
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an Adjacency List
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        int n = adj.size();
        vector<int> in_degree(n,0);
        queue<int> q;
        vector<int> ans;
        int adj_size{};

        for (int i = 0; i < n; i++) {
            for (int to : adj[i]) {
                in_degree[to]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int top = q.front(); q.pop();
            ans.push_back(top); 
            adj_size++;
            for (int to : adj[top]) {
                in_degree[to]--;
                if (in_degree[to] == 0) q.push(to);
            }
        }
        if (adj_size == n) return ans;
        else return {};
    }
};