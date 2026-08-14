#include <bits/stdc++.h>
using namespace std;

// Sub-Optimal Solution: The use of "set" which is a binary search tree under the hood
// that carries out O(log Visited) operations each time a new value is added significantly
// increases the overall time complexity

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        set<pair<int, int>> visited;
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && visited.find({r,c}) == visited.end()) {
                    bfs(r, c, rows, cols, visited, grid);
                    islands++;
                }
            }
        }
    }

private:
    void bfs(int r, int c, int rows, int cols, set<pair<int, int>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        visited.insert({r,c});
        q.push({r,c});

        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            vector<pair<int, int>> directions = {
                {-1, 0}, // Up
                {1, 0}, // Down
                {0, 1}, // Right
                {0, -1} // Left
            };
            
            for (auto& [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                if ((r >= 0 && r < rows) &&
                    (c >= 0 && c < cols) &&
                    grid[r][c] == '1' &&
                    visited.find({r,c}) == visited.end()) {
                        q.push({r,c});
                        visited.insert({r, c});
                    }
            }
        }
    }
};