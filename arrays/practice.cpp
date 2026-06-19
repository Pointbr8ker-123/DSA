#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

double findMedianSortedArraysOptimized(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArraysOptimized(nums2, nums1);

    int n1 = nums1.size(), n2 = nums2.size();
    int half = (n1+n2+1) / 2;
    int l = 0, r = n1;

    while (l <= r) {
        int cut1 = (l+r)/2;
        int cut2 = half - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n1 + n2) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else {
                return max(left1, left2);
            }
        } else if (left1 > right2) {
            r = cut1 - 1;
        } else {
            l = cut1 + 1;
        }
    }
    return 0.0;
}


int main() {
    vector<int> nums1 = {1, 3, 8, 9, 15}, nums2 = {7, 11, 18, 19, 21, 25};
    double median_2 = findMedianSortedArraysOptimized(nums1, nums2);

    cout << median_2 << endl;
    return 0;
}