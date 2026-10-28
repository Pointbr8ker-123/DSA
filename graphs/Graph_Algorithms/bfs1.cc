// BFS FROM A GIVEN SOURCE IN AN UNDIRECTED GRAPH
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> bfs(vector<vector<int>> &adj, int src) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;

    queue<int> q;
    visited[src] = true;

    q.push(src);

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        res.push_back(curr);

        for (int i : adj[curr]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return res;
}


// vector<vector<int>> createAdjList(vector<vector<int>> &edges) {
//     vector<vector<int>> adj(edges.size());
//     for (const auto &it : edges) {
//         adj[it[0]].push_back(it[1]);
//         adj[it[1]].push_back(it[0]);
//     }
//     return adj;
// }

// int main() {
//     vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {2,3}, {2,4}};
//     vector<vector<int>> adjList = createAdjList(edges);

//     int src = edges[0][0];
//     vector<int> res = bfs(adjList, src);

//     for (int i : res) {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }
