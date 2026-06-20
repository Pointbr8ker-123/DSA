#include <bits/stdc++.h>
using namespace std;

// Recall:
// left shift (<<) is integer multiplication by 2;
// right shift(>>) is integer division by 2;

class MaxHeap {
    int heap_size{};
    vector<int> max_heap{-1};

    private:
        int parent(int i) {return i>>1;};        // i.e i / 2;
        int leftChild(int i) {return i<<1;};     // i.e i * 2;
        int rightChild(int i) {return (i<<1)+ 1;}; // i.e i * 2 + 1;

    public:
        bool isEmpty() {return heap_size == 0;};
        int getMax() {return max_heap[1];};
        void insertItem(int val);
        void shiftUp(int i);
        int extractMax();
        void shiftDown(int i);
};


void MaxHeap::shiftUp(int i) {
    // we first check if the index "i" is actually within bounds, if not we stop the operation.
    if (i > heap_size) return;

    // since this would involve recursion, we need a base case to stop the recursion at some point.
    if (i == 1) return;

    // we compare the index of the new child to that of the direct parent and swap if the child is
    // greater, then we use recursion to keep comparing this same new element with its subsequent 
    // parents until we find the perfect position for it, or we reach the base case, in which case
    // it'd be the max element in the heap
    if (max_heap[i] > max_heap[parent(i)]) {
        swap(max_heap[parent(i)], max_heap[i]);
    }
    shiftUp(parent(i));
}


void MaxHeap::insertItem(int val) {
    // if the heap size + 1  (since the actual first value is at index 0 and is a dummy value) 
    // is equal (or in rare cases greater), then we create more space using push_back function
    // to insert another dummy value e.g 0, to create space where we can insert the new value
    // after incrementing the heap_size. 
    
    // In the implementation below, we can use a concise to kill two birds with one stone.
    if (heap_size + 1 >= max_heap.size()) {
        max_heap.push_back(0);
    }
    max_heap[++heap_size] = val;
    shiftUp(heap_size);
    return;
}


void MaxHeap::shiftDown(int i) {
    // as usual we check if the index "i" is withing bounds of the heap_size
    if (i > heap_size) return;

    // we set up a swap id that would help us compare both the left and right child to the parent
    // in the same iteration before any swap can happen to make sure we are swapping the right child
    int swap_id = i;

    // we first check if the left child's index is withing bounds, and then if it is greater than the parent
    if (leftChild(i) <= heap_size && max_heap[i] < max_heap[leftChild(i)]) {
        swap_id = leftChild(i);
    }

    // we also check if the right child is greater than the left child (i.e if the left child is greater
    // also greater than the parent) or the parent (i.e if the left child is less than the parent and we
    // didnt enter the if statement above)
    if (rightChild(i) <= heap_size && max_heap[swap_id] < max_heap[rightChild(i)]) {
        swap_id = rightChild(i);
    }

    // if the swap id is not equal to the parent (which is "i" in this case), then we keep swapping
    // using recursion to go down the heap till we are able to get a correct heap structure
    if (swap_id != i) {
        swap(max_heap[i], max_heap[swap_id]);
        shiftDown(swap_id);
    }
    return;
}


int MaxHeap::extractMax() {
    int maxVal = max_heap[1];
    max_heap[1] = max_heap[heap_size];
    heap_size--;
    shiftDown(1);
    return maxVal;
}


int main() {
    MaxHeap* PriorityQueue = new MaxHeap();
    if (PriorityQueue->isEmpty()) {
        cout << "This is correct... Heap should be empty at this stage." << endl;
    } else {
        cout << "There is something wrong with the isEmpty implementation." << endl;
    }

    PriorityQueue->insertItem(10);
    PriorityQueue->insertItem(20);
    PriorityQueue->insertItem(130);
    PriorityQueue->insertItem(10000);
    PriorityQueue->insertItem(2);
    PriorityQueue->insertItem(56);
    PriorityQueue->insertItem(1900000);

    if (PriorityQueue->isEmpty()) {
        cout << "There is something wrong with the isEmpty implementation." << endl;
    } else {
        cout << "This is correct... it is filled with values now." << endl;
    }

    cout << PriorityQueue->getMax() << endl;
    PriorityQueue->extractMax();
    cout << PriorityQueue->getMax() << endl;

    return 0;
}