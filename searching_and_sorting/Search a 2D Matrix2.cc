#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(),
        cols = matrix[0].size(),
        row = 0, col = cols-1;

    while (row < rows && col > -1) {
        int curr = matrix[row][col];
        if (curr == target) return true;
        if (curr > target) col--;
        else row++;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 19;

    bool ans = searchMatrix(matrix, target);
    cout << boolalpha;
    cout << ans << endl;

    return 0;
}