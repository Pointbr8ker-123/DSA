#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int ans = 1;
    int num = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] == num) {
            remove(nums.begin(), nums.end(), nums[i]);
        } else {
            num = nums[i];
            ans++;
        }
    }
    return nums;
}

int main() {
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    vector<int> ans = removeDuplicates(arr);

    for (int a : ans) cout << a << " ";
    cout << endl;
    return 0;
}