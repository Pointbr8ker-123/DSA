// priority queue implementation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;

        // push all the values in the stones array to the 
        // max heap so we can easily extract the top 2
        for (int w : stones) {
            max_heap.push(w);
        }

        // we use a while loop to keep carrying out popping and
        // pushing operations till we have either an empty heap
        // or 1 element left in the heap
        while (max_heap.size() > 1) {
            // since its a max heap, the max_heap.top() is the 
            // current largest element, we store the value and 
            // pop it from the heap
            int y = max_heap.top();
            max_heap.pop();

            // now the second largest element becomes the largest
            // element and we do the same; store and pop
            int x = max_heap.top();
            max_heap.pop();

            // we compare the two stored values and pushback the
            // difference; if equal, we pushback 0. This makes sense
            // since if there is a last value > 0, that is our remainder,
            // and if there is no value left, then all the values will be
            // 0 anyways from the subtraction (signifying an empty heap)
            max_heap.push(y - x);
        }
        // we just have to return the top of the heap which would either be
        // the last remaining value, or 0 if the heap is supposed to be empty
        return max_heap.top();
    }
};