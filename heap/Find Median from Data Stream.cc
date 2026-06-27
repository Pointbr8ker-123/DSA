#include <bits/stdc++.h>
using namespace std;


class MedianFinder {
private:
    // create a maxheap and a minheap to track median value(s)
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // push the new value 'num' into the maxheap first and then
        // into the minheap next, then pop from the maxheap
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        
        // check if they're of equal sizes, if theyre not, then we 
        // push back the top element from the minheap back to the 
        // maxheap. This is to ensure that the middle element is
        // at the top of the maxheap at all times, and if theyre
        // are 2 middle elements, then theyre both at the tops of
        // the maxheap and minheap at all times.
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        // if there's only one median value, then it'd be the root
        // value of the maxheap
        if (maxheap.size() > minheap.size()) return maxheap.top();

        // but if there are 2 median values, then they'd be the root
        // values of the min and max heaps, so we just return a median
        // of the two values as our answer
        else {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// BRUTE FORCE -- INEFFICIENT
// class MedianFinder {
// private:
//     vector<int> nums;

// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         nums.push_back(num);
//         sort(nums.begin(), nums.end());
//     }
    
//     double findMedian() {
//         double median;
//         int n = nums.size();
//         if (n % 2 != 0) {
//             median = nums[n/2];
//         } else {
//             median = (nums[n/2] + nums[n/2 + 1]) / 2.0;
//         }
//         return median;
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */