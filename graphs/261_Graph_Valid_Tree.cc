#include <bits/stdc++.h>
using namespace std;


bool dfs(int node, int parent, vector<vector<int>>& al, vector<bool>& visited) {
    // if we've encountered this node before, then there is a cycle and
    // the graph is an invalid tree
    if (visited[node]) return false;

    // set the node to visited
    visited[node] = true;

    for (int neighbour : al[node]) {
        // This helps prevent the connection to the parent as a cycle
        // therefore flagging a cycle only when it exists between two
        // nodes connected to the same "parent" and connected to each
        // other
        if (neighbour == parent) continue;
        if (!dfs(neighbour, node, al, visited)) return false;
    }
    return true;
}

bool graph_valid_tree(int n, vector<vector<int>>& edges) {
    // if number of edges isnt n-1, then it is not a valid tree
    if (edges.size() != n-1) return false;

    // Build adjacency list
    vector<vector<int>> al(n);
    for (const auto& edge : edges) {
        int nodeA = edge[0];
        int nodeB = edge[1];

        al[nodeA].push_back(nodeB);
        al[nodeB].push_back(nodeA);
    }

    vector<bool> visited(n, false);
    
    if (!dfs(0, -1, al, visited)) return false;

    // Check every node to make sure they were all visited. If
    // there is any unvisited node, then it is disconnected and
    // therefore makes the graph an invalid tree
    for (bool node : visited) {
        if (!node) return false;
    }

    return true;
}
