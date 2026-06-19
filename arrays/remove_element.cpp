#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;

    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int val = 0;

    int k = removeElement(nums, val);
    cout << k << endl;
    return 0;
}