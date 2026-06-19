#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int j = 0, k = n - 1;

    int max_area = INT_MIN;
    while(j < k) {
        int area = (k - j) * min(height[j], height[k]);
        max_area = max(max_area, area);
        
        if(height[j] < height[k]) j++;
        else k--;
    }
    return max_area;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(height);
    cout << ans << endl;
    
    return 0;
}