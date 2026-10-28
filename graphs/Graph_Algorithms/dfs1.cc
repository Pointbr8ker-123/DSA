//  DFS FROM A GIVEN SOURCE
#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res) {
    visited[s] = true;
    res.push_back(s);

    for (int i : adj[s]) {
        if (visited[i] == false) 
            dfsHelper(adj, visited, i, res);
    }
}

vector<int> dfs(vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsHelper(adj, visited, 0, res);
    return res;
}

vector<vector<int>> createAdjList(vector<vector<int>> &edges) {
    vector<vector<int>> adj(edges.size());
    for (const auto &it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}

int main() {
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {2,3}, {2,4}};
    vector<vector<int>> adjList = createAdjList(edges);
    vector<int> res = dfs(adjList);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
