#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int cap;
    int head;
    int tail;
    int size;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        cap = k;
        head = 0;
        tail = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        tail = (tail + 1) % cap;
        data[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % cap;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */