#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    q.push({r,c});
                }
            }
        }

        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i< n; i++) {
                auto [r,c] = q.front(); q.pop();
                int sur = 0;
                for (auto& [dr,dc] : dirs) {
                    int nr = dr+r, nc = dc+c;
                    if ((nr >= 0 && nr < rows) && (nc >= 0 && nc < cols)) {
                        sur++;
                    }
                }
                if (sur == 4) board[r][c] = 'X';
            }
        }
    }
};