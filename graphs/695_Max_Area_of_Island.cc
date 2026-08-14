#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int new_area = dfs(r, c, rows, cols, grid);
                    max_area = max(max_area, new_area);
                }
            }
        }
        return max_area;
    }

private:
    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0;

        int new_area = 1;
        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();

            for (auto& [dr, dc] : directions) {
                int nr = dr + row;
                int nc = dc + col;

                if ((nr >= 0 and nr < rows) and
                    (nc >= 0 and nc < cols) and
                    grid[nr][nc] == 1) {
                        new_area++;
                        q.push({nr, nc});
                        grid[nr][nc] = 0;
                    }
            };
        }
        return new_area;
    }
};