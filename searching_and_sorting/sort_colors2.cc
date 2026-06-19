#include <bits/stdc++.h>
using namespace std;

void swap_elements(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int curr = 0;

    while (curr <= high) {
        if (nums[curr] == 0) {
            swap_elements(nums, curr, low);
            curr++;
            low++;
        } else if (nums[curr] == 2) {
            swap_elements(nums, curr, high);
            high--;
        } else curr++;
    }
}