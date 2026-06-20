// Implementation of a mean heap + Priority Queue

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int heap_size{};
    vector<int> min_heap{-1};

    private:
        int parent(int i) {return i>>1;};
        int leftchild(int i) {return i<<1;};
        int rightchild(int i) {return (i<<1) + 1;};

    public:
        bool isEmpty() {return heap_size == 0;};
        int getMin() {return min_heap[1];};
        void insertItem(int val);
        void shiftUp(int i);
        void shiftDown(int i);
        int extractMin();
};

void MinHeap::shiftUp(int i) {
    if (i > heap_size) return;

    if (i == 1) return;

    if (min_heap[i] < min_heap[parent(i)]) {
        swap(min_heap[i], min_heap[parent(i)]);
    }
    shiftUp(parent(i));
}

void MinHeap::insertItem(int val) {
    if (heap_size + 1 >= min_heap.size()) {
        min_heap.push_back(0);
    }
    min_heap[++heap_size] = val;
    shiftUp(heap_size);
    return;
}

void MinHeap::shiftDown(int i) {
    if (i > heap_size) return;

    int swap_id = i;

    if (leftchild(i) <= heap_size && min_heap[leftchild(i)] < min_heap[i]) {
        swap_id = leftchild(i);
    }

    if (rightchild(i) <= heap_size && min_heap[rightchild(i)] < min_heap[swap_id]) {
        swap_id = rightchild(i);
    }

    if (swap_id != i) {
        swap(min_heap[i], min_heap[swap_id]);
        shiftDown(swap_id);
    }
    return;
}

int MinHeap::extractMin() {
    int minVal = min_heap[1];
    swap(min_heap[1], min_heap[heap_size--]);
    shiftDown(1);
    return minVal;
}

int main() {
    MinHeap* PriorityQueue = new MinHeap();
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

    cout << PriorityQueue->getMin() << endl;
    PriorityQueue->extractMin();
    cout << PriorityQueue->getMin() << endl;

    return 0;
}