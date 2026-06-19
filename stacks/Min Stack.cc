#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    vector<vector<int>> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int _min = getMin();
        if (stack.empty() || _min > val) {
            _min = val;
        }
        stack.push_back({val, _min});
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        if (stack.empty()) return -1;
        else return stack.back()[0];
    }
    
    int getMin() {
        if (stack.empty()) return -1;
        else return stack.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */