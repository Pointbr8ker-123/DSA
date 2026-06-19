#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int m_id = m - 1;
    int n_id = n - 1;
    int r = (m + n) - 1;

    while(n_id >= 0) {
        if(m_id >= 0 && nums1[m_id] > nums2[n_id]) {
            nums1[r] = nums1[m_id];
            m_id--;
        } else {
            nums1[r] = nums2[n_id];
            n_id--;
        }
        r--;
    }
}
