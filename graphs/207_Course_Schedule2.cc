#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an Adjacency List (Directed Graph)
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            // Recall: in [u, v], u depends on v... i.e u -> v
            adj[edge[1]].push_back(edge[0]);
        }

        int n = adj.size();
        vector<int> in_degree(n, 0); // Tracks the number/degree of incoming connections
        queue<int> q;
        int adj_size{}; // This will track the number of nodes in the graph that have been processed

        // Populate the in_degree array
        for (int i = 0; i < n; i++) {
            for (int to : adj[i]) {
                in_degree[to]++;
            }
        }

        // First fill in the queue with nodes/vertices that have no/0 incoming connections
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        // Use BFS to perform topological sort on the graph starting from the vertices with
        // the least number of incoming connections. In this particular case, we'll use "adj_size"
        // to track how many vertices were processed. If there are unreachable vertices, there
        // must be a cycle present and this will reflect in "adj_size" not being equal to n.
        while(!q.empty()) {
            int top = q.front(); q.pop();
            adj_size++;
            for (int to : adj[top]) {
                in_degree[to]--;
                if (in_degree[to] == 0) q.push(to);
            }
        }

        return (adj_size == n);
    }
};