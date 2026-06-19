#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Optimum approach: Sliding Window Approach
bool containsNearbyAlmostDuplicate_2(vector<int>& nums, int indexDiff, int valueDiff) {
    set<int> window;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        auto pos = window.lower_bound((long)nums[i] - valueDiff);
        if (pos != window.end() && *pos - nums[i] <= valueDiff) {
            return true;
        }
        window.insert(nums[i]);

        if (i >= indexDiff) {
            window.erase(nums[i - indexDiff]);
        }
    }
    return false;
}


// Brute force approach
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + indexDiff && j < n; j++) {
            if (abs((long)nums[i] - nums[j]) <= valueDiff) return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1,5,9,1,5,9};
    int indexDiff = 2, valueDiff = 3;

    cout << boolalpha;
    cout << containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);
    cout << endl;

    return 0;
}