#include <bits/stdc++.h>
using namespace std;

// Optimal Solution: Floyd’s Tortoise and Hare (cycle detection)

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    
    while(true) {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast) break;
    }

    int slow2 = nums[0];

    while(slow != slow2) {
        slow = nums[slow];
        slow2 = nums[slow2];
    }
    
    return slow;
}



int main() {
    vector<int> nums = {1,3,4,2,2};
    int out = findDuplicate(nums);

    cout << out << endl;
    return 0;
}
