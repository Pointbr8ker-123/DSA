// BFS OF A DISCONNECTED UNDIRECTED GRAPH
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfsHelper(vector<vector<int>> &adj, int src, 
vector<bool> &visited, vector<int> &res) {
    visited[src] = true;
    queue<int> q;
    
    q.push(src);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        res.push_back(curr);
        
        for (int i : adj[curr]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

vector<int> bfs(vector<vector<int>> &adj) {
    int V = adj.size();

    vector<bool> visited(V, false);
    vector<int> res;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfsHelper(adj, i, visited, res);
        }
    }
    return res;
}


vector<vector<int>> createAdjList(vector<vector<int>> &edges) {
    vector<vector<int>> adj(6);
    for (const auto &it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}

int main() {
    vector<vector<int>> edges = {{0, 2}, {0, 3}, {1, 2}, {4, 5}};
    vector<vector<int>> adjList = createAdjList(edges);

    vector<int> res = bfs(adjList);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}