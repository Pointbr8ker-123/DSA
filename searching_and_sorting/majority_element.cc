#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> track;
    for (int i = 0; i < nums.size(); i++) {
        track[nums[i]]++;
    }

    int max_val = INT_MIN;
    int max_key;
    for (auto& pair : track) {
        if (pair.second > max_val) {
            max_val = pair.second;
            max_key = pair.first;
        }
    }

    return max_key;
}