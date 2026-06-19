#include <bits/stdc++.h>
using namespace std;

// Time Complexity: 0(m * n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    for (int i = 0; i < n; i ++) {
        if (matrix[i][0] == target) return true;

        if (matrix[i][0] < target) {
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == target) return true;
            }
        } else {
            continue;
        }
    }   
    return false;     
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 34;

    bool ans = searchMatrix(matrix, target);
    cout << boolalpha;
    cout << ans << endl;

    return 0;
}