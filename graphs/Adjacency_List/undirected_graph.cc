#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> createList(int V, vector<vector<int>> &edges) {
    // Create an adjacency list to check how each element is connected to the others
    vector<vector<int>> list(V);
    for (const auto &it : edges) {
        list[it[0]].push_back(it[1]);
        list[it[1]].push_back(it[0]);
    }
    return list;
}


int main() {
    int V = 3;

    // List of edges (u, v)
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 2} };

    // Build the graph using edges
    vector<vector<int>> adj = createList(V, edges);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < V; i++) {
        
        // Print the vertex
        cout << i << ": "; 
        for (int j : adj[i]) {
            
            // Print its adjacent
            cout << j << " "; 
        }
        cout << endl; 
    }

    return 0;
}