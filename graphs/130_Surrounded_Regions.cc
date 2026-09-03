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
                // Push into the queue every occurance of "O" that is situated at
                // the boundary
                if (r == 0 || c == 0 || r == rows-1 || c == cols-1) 
                    if (board[r][c] == 'O') {
                        q.push({r,c});
                        // Mark any "O" found on the boundary for later purposes
                        board[r][c] = '$';
                    }
            }
        }

        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i< n; i++) {
                auto [r,c] = q.front(); q.pop();
                for (auto& [dr,dc] : dirs) {
                    int nr = dr+r, nc = dc+c;
                    // Check if there are any "0"s connected to the "O" on the boundary
                    // If there is/are any, then that cell/cells cannot be "surrounded"
                    // and will therefore be marked as "unsurroundable" with the "$" sign
                    if ((nr >= 0 && nr < rows) && 
                        (nc >= 0 && nc < cols) &&
                        board[nr][nc] == 'O') {
                            q.push({nr,nc});
                            board[nr][nc] = '$';
                    }
                }
            }
        }

        // Traverse the grid and check out for unsurroundable cells marked '$'
        // if we find any "O" that isnt marked '$', then that cells can be
        // surrounded and thus marked 'X'... else we'd unmark it back to an 'O'
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == '$') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                };
            }
        }
    }
};