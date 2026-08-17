#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    // mark this node as visted as we just visited it
    visited[node] = true;

    // Go through the adjancency list to check the nodes connected to it
    // if we havent visited the nodes connected to it, we explore them
    // recursively till we're done exploring all the nodes connected to
    // this one node

    // In doing so, we would have completely found one complete component
    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjacencyList, visited);
        }
    }

}


int countComponents(int n, vector<vector<int>>& edges) {
    // Build an Adjacency list to track how the nodes are
    // connected to each other
    vector<vector<int>> adjacencyList(n);
    for (const auto& edge : edges) {
        int nodeA = edge[0];
        int nodeB = edge[1];

        adjacencyList[nodeA].push_back(nodeB);
        adjacencyList[nodeB].push_back(nodeA);
    }
    
    // use an array of booleans to track which nodes have been visited
    // and which ones havent
    vector<bool> visited(n, false);

    int components = 0;

    // iterate from 0 - n-1 (i.e every possible value in the graph) and
    // check for connections with the help of the "visited" array above
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adjacencyList, visited);
            components++;
        }
    }
    return components;
}

// Overall Time Complexity = O(V + E)
// Overall Space Complexity = O(V + E)
