#include <bits/stdc++.h>
using namespace std;

int b_search(vector<int>& nums, int target, bool search_left) {
    int l = 0, r = nums.size() - 1, id = -1;
    while (l <= r) {
        int mid = l + (r - l)/2;
        if (nums[mid] > target) r = mid - 1;
        else if (nums[mid] < target) l = mid + 1;
        else {
            id = mid;
            if (search_left) r = mid - 1;
            else l = mid + 1;
        }
    }
    return id;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1,-1};
    int left = b_search(nums, target, true);
    int right = b_search(nums, target, false);
    res[0] = left;
    res[1] = right;
    return res;
}


int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> tar = searchRange(nums, target);

    for (int n : tar) cout << n << " ";
    cout << endl;

    return 0;
}