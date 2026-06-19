#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l)/2;
            if (calc_hrs(piles, mid) <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

private:
    long long calc_hrs(vector<int>& piles, int mid) {
        long long hours = 0;
        for (long long p : piles) hours += (p + mid - 1) / mid;
        return hours;
    }
};