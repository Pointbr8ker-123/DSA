#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


typedef long long ll;

struct AdjEntry {
    int vertex;
    AdjEntry* twin;

    AdjEntry(int v) {
        vertex = v;
        twin = nullptr;
    }
};


// Adjacency List (It'd be a Global variable for convinience sake)
vector<vector<AdjEntry*>> adjList(3);

void addEdge(vector<vector<AdjEntry*>> &adjList, vector<vector<int>> &edges) {
    // This function populates the adjacency list from the "edges"
    for (const auto &it : edges) {
        int u = it[0];
        int v = it[1];

        AdjEntry* a = new AdjEntry(u);
        AdjEntry* b = new AdjEntry(v);

        adjList[u].push_back(b);
        adjList[v].push_back(a);
    }
}


void setTwinPointers(vector<vector<AdjEntry*>> &adjList) {
    // THis function uses a hashmap to track twin entries in the adjacency list and 
    // sets a pointer that connects them
    unordered_map<ll, AdjEntry*> hMap;

    int n = adjList.size();

    for (int i = 0; i < n; i++) {
        for (AdjEntry* entry : adjList[i]) {
            int v = entry->vertex;
            ll key = 1LL * v * n + i;
            hMap[key] = entry;
        }
    }

    for (int j = 0; j < n; j++) {
        for (AdjEntry* entry : adjList[j]) {
            int v = entry->vertex;
            ll twin_key = 1LL * j * n + v;
            entry->twin = hMap[twin_key];
        }
    }
}

// Time Complexity -> O(V + E)