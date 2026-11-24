#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pac(rows, vector<int>(cols, 0));
        vector<vector<int>> atl(rows, vector<int>(cols, 0));
        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        for (int r = 0; r < rows; r++) {
            pacQ.push({r,0}); // Pacific Ocean (Left Row)
            pac[r][0] = 1;

            atlQ.push({r,cols-1}); // Atlantic Ocean (Right row)
            atl[r][cols-1] = 1;
        }

        for (int c = 0; c < cols; c++) {
            pacQ.push({0,c});  // Pacific Ocean (Top Row)
            pac[0][c] = 1;

            atlQ.push({rows-1, c});  // Atlantic Ocean (Bottom Row)
            atl[rows-1][c] = 1;
        }

        bfs(rows, cols, heights, pac, pacQ);
        bfs(rows, cols, heights, atl, atlQ);

        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) {
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }

private:
    void bfs(int rows, int cols, vector<vector<int>> &heights, 
        vector<vector<int>>& visited, queue<pair<int,int>>& q) {

            vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

            while(!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                for (auto& [dr,dc] : dirs) {
                    int nr = dr + r, nc = dc + c;
                    if ((nr >= 0 && nr < rows) &&
                        (nc >= 0 && nc < cols) &&
                        (!visited[nr][nc] && heights[nr][nc] >= heights[r][c])) {
                            visited[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                }
            }
    }
};