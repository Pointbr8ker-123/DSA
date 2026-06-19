#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        else {
            if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    int output = search(nums, target);
    cout << output << endl;

    return 0;
}