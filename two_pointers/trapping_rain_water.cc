#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int leftmax = height[l], rightmax = height[r];

    int ans = 0;
    while(l < r) {
        if (leftmax < rightmax) {
            l++;
            leftmax = max(leftmax, height[l]);
            ans += (leftmax - height[l]);
        } else {
            r--;
            rightmax = max(rightmax, height[r]);
            ans += (rightmax - height[r]);
        }
    }
    return ans;
}

int main() {
    vector<int> height = {4,2,0,3,2,5};
    int ans = trap(height);

    cout << ans << endl;
    return 0;
}