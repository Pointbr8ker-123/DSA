#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> track;
    for (int i = 0; i < nums.size(); i++) {
        int current_value = nums[i];
        int x = target - current_value;

        if (track.find(x) != track.end()) {
            return {track[x], i};
        }
        track[nums[i]] = i;
    }
    return {};
}


int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> two_sum = twoSum(nums, target);

    for (int val : two_sum) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
} 