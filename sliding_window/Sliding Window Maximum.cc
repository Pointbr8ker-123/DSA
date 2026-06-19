#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>ans;
        deque<int>dq;//we'll store indexes HERE
        for(int i=0;i<n;i++){
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front()==i-k){
                dq.pop_front();
            }
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};