#include <bits/stdc++.h>
using namespace std;


// More Optimal Solution: Instead of Having a "visited" set, we just set the 
// value of any visited {r,c} to zero
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        if (grid.empty()) return 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    bfs(r, c, rows, cols, grid);
                    islands++;
                }
            }
        }
        return islands;
    }

private:
    void bfs(int r, int c, int rows, int cols, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '0';

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };

        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            
            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;

                if ((nr >= 0 && nr < rows) &&
                    (nc >= 0 && nc < cols) &&
                    grid[nr][nc] == '1') {
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
            }
        }
    }
};
