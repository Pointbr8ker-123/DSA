#include <bits/stdc++.h>
using namespace std;

// HINT: Multi-source BFS starting from all gates

// "Multi-source BFS means: use a queue, but the BFS should 
// start from every gate at the same time and stretch outward. 
// We achieve this by first pushing all gates into the queue 
// using a for-loop. Then we run BFS normally. As we explore, 
// any new empty rooms we encounter get added to the queue. We 
// keep going until we've visited every reachable cell in the grid."

vector<vector<int>> map_gate_distances(vector<vector<int>>& dungeon_map) {
    int rows = dungeon_map.size();
    int cols = dungeon_map[0].size();
    queue<pair<int,int>> q;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (dungeon_map[r][c] == 0) {
                q.push({r,c});
            }
        }
    }

    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    // This tracks how far we are from from the gates "0"
    int dist = 0;

    while(!q.empty()) {
        int n = q.size();
        // initially starts with tracking the gates and finding out 
        for (int i = 0; i < n; i++) {
            auto[r,c] = q.front(); q.pop();
            for (auto& [dr,dc] : dirs) {
                int nr = dr + r, nc = dc + c;
                if ((nr >= 0 && nr < rows) &&
                    (nc >= 0 && nc < cols) &&
                    dungeon_map[nr][nc] == INT_MAX) {
                        dungeon_map[nr][nc] = dist + 1;
                        q.push({nr, nc});
                    }
            }
        }
        dist++;
    }
    return dungeon_map;
}
