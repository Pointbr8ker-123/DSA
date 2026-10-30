#include <bits/stdc++.h>
using namespace std;

// DFS SOLUTION
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Create a hashset to store the nodes we have visited
        unordered_set<int> visited;

        // This is used to track the number of "provinces"
        int provinces = 0;

        // We iterate through every "city" in the graph while using
        // dfs to search the adjacency matrix to check for connections
        // to the current city we're considering

        // If we're able to find all the other cities a particular city
        // is connected to (whether directly or indirectly), we've
        // found a province and can incrememnt the variable
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited.find(i) == visited.end()) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }

private:
    void dfs(int city, vector<vector<int>>& isConnected, unordered_set<int>& visited) {
        visited.insert(city);
        for (int cur = 0; cur < isConnected[city].size(); cur++) {
            int connected = isConnected[city][cur];
            if (connected == 1 && visited.find(cur) == visited.end()) {
                dfs(cur, isConnected, visited);
            }
        }
    }
};



// ================================= MORE COMPACT DFS SOLUTION ==================================
class Solution {
private:
    void dfs(int city, int n, vector<int> &visited, vector<vector<int>>& isConnected) {
        visited[city] = 1;
        for (int neigh = 0; neigh < n; neigh++) {
            if (isConnected[city][neigh] == 1 && !visited[neigh]) {
                dfs(neigh, n, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, n, visited, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};