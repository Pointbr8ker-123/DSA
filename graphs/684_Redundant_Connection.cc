#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Using Union Find (Disjoint Set Union) Approach
    vector<int> parent;
    vector<int> rank;

    // Returns the "parent" of the node
    int find(const int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path Compression
        }
        return parent[x];
    }

    // Links two nodes together; uses "rank" to decide the "parent" 
    // and the "child"
    void unite(const int a, const int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b) return;

        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else {
            parent[root_a] = root_b;
            rank[root_b]++;
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if (find(a) == find(b)) return edge;
            unite(a, b);
        }
        return {};
    }
};