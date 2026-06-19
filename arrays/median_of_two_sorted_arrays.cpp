#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> merge(vector<int> left_arr, vector<int> right_arr) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] < right_arr[j]) {
            res.push_back(left_arr[i]);
            i++;
        } else {
            res.push_back(right_arr[j]);
            j++;
        }
    }
    res.insert(res.end(), left_arr.begin() + i, left_arr.end());
    res.insert(res.end(), right_arr.begin() + j, right_arr.end());
    return res;
}

// Brute Force approach... Time complexity = O(m+n). m beign the size of the first array, and n beign the size of the second array
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> new_arr = merge(nums1, nums2);

    int l = 0, r = new_arr.size() - 1;
    if (new_arr.size() % 2 == 0) {
        while (l < r) {
            l++;
            r--;
        }
        return ((double)new_arr[l] + new_arr[r])/2;
    } else {
        return new_arr[new_arr.size()/2];
    }
}

// Optimized Solution using Binary Search... Time Complexity: O(log(m+n))
double findMedianSortedArraysOptimized(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) 
        return findMedianSortedArrays(nums2, nums1); // ensure nums1 is smaller

    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0; // unreachable
}


int main() {
    vector<int> nums1 = {1, 3, 8, 9, 15}, nums2 = {7, 11, 18, 19, 21, 25};
    double median = findMedianSortedArrays(nums1, nums2);
    double median_2 = findMedianSortedArraysOptimized(nums1, nums2);

    cout << median << endl;
    cout << median_2 << endl;
    return 0;
}