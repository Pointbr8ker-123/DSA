// BFS SOLUTION TO LEETCODE 547
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int city, int n, 
        vector<int> &visited, 
        vector<vector<int>>& isConnected) {
            queue<int> q;
            q.push(city);
            visited[city] = 1;

            while(!q.empty()) {
                int curr = q.front(); q.pop();
                for (int neighbors = 0; neighbors < n; neighbors++) {
                    if (isConnected[curr][neighbors] == 1 and !visited[neighbors]) {
                        q.push(neighbors);
                        visited[neighbors] = 1;
                    }
                }
            }
        }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Number of cities involed
        int n = isConnected.size();

        // Use a vector (of 0s and 1s) to track visited cities and neighbors
        vector<int> visited(n, 0);

        // This returns the number of provinces after the solution
        int provinces = 0;

        // Since the number of cities start from 1 to n, iterate from 1 to n
        // to find cities that have been visited and check the connections 
        // between them
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, n, visited, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};