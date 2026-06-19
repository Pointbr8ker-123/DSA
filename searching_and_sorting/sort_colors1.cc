#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int l, int h) {
    int mid = (l + (h - l)) / 2;
    int a = nums[l];
    int b = nums[mid];
    int c = nums[h];

    int median;
    if ((a < b && b < c) || (c < b && b < a)) median = mid;
    else if ((a < c && c < b) || (b < c && c < a)) median = h;
    else median = l;

    swap(nums[l], nums[median]);

    int pivot = nums[l];
    int i = l+1;
    int j = h;

    while(true) {
        while(i <= j && nums[i] < pivot) i++;
        while(i <= j && nums[j] > pivot) j--;
        if (i >= j) break;
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    swap(nums[l], nums[j]);
    return j;
}

void quick_sort_helper(vector<int>& nums, int l, int h) {
    if (l < h) {
        int pivot = partition(nums, l, h);
        quick_sort_helper(nums, l, pivot-1);
        quick_sort_helper(nums, pivot+1, h);
    }
}

void sortColors(vector<int>& nums) {
    if (nums.size() <= 1) return;
    quick_sort_helper(nums, 0, nums.size()-1);
}