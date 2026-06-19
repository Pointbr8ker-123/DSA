//Leetcode 15: 3Sum

// Steps:
// 1. Create an array of arrays to store the answer
// 2. sort the array so you can find duplicates more easily.
// 3. using three pointers, iterate through the array using the first pointer
// 4. use the first pointer to check for duplicates and "continue" if none is found.
// 5. use the second and third pointers to iterate through
//  the array again using a second loop to check if the sum of the values
//  at the two pointers and the original pointers are == 0
// 6. if they are (== 0), then save the values at the three pointers to the answer array
// else keep moving the pointers (i.e if > 0 move back the right and if < 0 move front the left).
// 7. if  not, the loop continues, but not without checking for duplicates of the values at
// the second and third pointers.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int j = i+1, k = n-1;
        while(j < k) {
            int s = nums[i] + nums[j] + nums[k];
            if (s < 0) j++;
            else if (s > 0) k--;
            else {
                ans.push_back({nums[i], nums[j], nums[k]});

                while(j < k && nums[j] == nums[j+1]) j++;
                while(j < k && nums[k] == nums[k-1]) k--;

                j++;
                k--;
            }
        }
    }
    return ans;
}