#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Create a hashmap to store the nodes we have visited
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