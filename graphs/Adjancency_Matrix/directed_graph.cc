#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createMatrix(int V, vector<vector<int>> &edges) {
    vector<vector<int>> mat(V, vector<int>(V, 0));

    for (auto &it : edges) {
        int x = it[0];
        int y = it[1];
        mat[x][y] = 1;
    }
    return mat;
}

int main() {
    vector<vector<int>> edges = {{1, 0},{2, 0},{1, 2}};
    int V = edges.size();

    vector<vector<int>> mat = createMatrix(V, edges);

    cout << "Adjancency Matrix Implementation" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << mat[i][j] <<  " ";
        }
        cout << endl;
    }
    return 0;
}