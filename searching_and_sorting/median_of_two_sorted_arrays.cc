#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(),
            n2 = nums2.size(),
            half = (n1+n2+1)/2;

        int l = 0, r = n1;
        while(l <= r) {
            int cut1 = (l + r)/2,
                cut2 = half - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1],
                l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1],

                r1 = (cut1 == n1) ? INT_MAX : nums1[cut1],
                r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
                
            if (l1 <= r2 && l2 <= r1) {
                if ((n1+n2) % 2 == 0) return (max(l1,l2) + min(r1,r2)) / 2.0;
                else return max(l1, l2);
            } else if (l1 > r2) {
                r = cut1 - 1;
            } else {
                l = cut1 + 1;
            }
        }
        return 0.0;
    }
};