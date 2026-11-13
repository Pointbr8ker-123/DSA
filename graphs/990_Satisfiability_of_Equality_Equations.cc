#include <bits/stdc++.h>
using namespace std;


class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b) {
        int root_a = find(a), root_b = find(b);
        if (root_a == root_b) return;

        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else {
            parent[root_b] = root_a;
            rank[root_a]++;
        }
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);

        for (const auto& eqn : equations) {
            int id_xi = eqn[0] - 'a';
            int id_yi = eqn[3] - 'a';

            if (eqn[1] == '=') {
                uf.unite(id_xi, id_yi);
            }
        }
        
        for (const auto& eqn : equations) {
            int id_xi = eqn[0] - 'a';
            int id_yi = eqn[3] - 'a';

            if (eqn[1] == '!') {
                if (uf.find(id_xi) == uf.find(id_yi)) return false;
            }
        }
        
        return true;
    }
};

