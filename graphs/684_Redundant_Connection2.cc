#include <bits/stdc++.h>
using namespace std;

// Implementation using the union find as a separate class (Just to master C++ syntax better tho)
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind (int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void _union(int x, int y) {
        int node_x = find(x);
        int node_y = find(y);

        if (node_x == node_y) return;

        if (rank[node_x] > rank[node_y]) {
            parent[node_y] = node_x;
        } else if (rank[node_x] < rank[node_y]) {
            parent[node_x] = node_y;
        } else {
            parent[node_x] = node_y;
            rank[node_y]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (uf.find(a) == uf.find(b)) return edge;
            uf._union(a, b);
        }
        return {};
    }
};
