#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Count the number of fresh oranges
                if (grid[r][c] == 1) fresh++;
                // Push the grid location of the rotten oranges into the queue
                else if (grid[r][c] == 2) q.push({r,c});
            }
        }

        // if there are no fresh oranges, then the rotting process was already
        // complete and hence does not need more "minutes" so we return 0
        if (fresh == 0) return 0;

        vector<pair<int,int>> dirs = {{0,1}, {0,-1,}, {1,0}, {-1,0}};

        // Set the no. of minutes to -1 as its initial state which would
        // be updated to 0 after the fits
        int ans = -1;

        // Use bfs to process each rotten orange and its 4-dimensionally related
        // neiggbours to check if there are fresh oranges to rot
        while(!q.empty()) {
            int n = q.size();
            ans++;
            for (int i = 0; i < n; i++) {
                auto [r, c] = q.front(); q.pop();
                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if ((nr >= 0 && nr < rows) &&
                        (nc >= 0 && nc < cols) &&
                        grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            fresh--;
                            q.push({nr, nc});
                        }
                }
            }
        }
        // if all the fresh oranges were rotted, we return how many minutes it took
        // to do, if not, then we have an unconnected node/orange so we return -1
        return (fresh == 0) ? ans : -1;
    }
};