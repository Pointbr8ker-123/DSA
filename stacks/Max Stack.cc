#include <bits/stdc++.h>
using namespace std;

class MaxStack {
private:
    vector<pair<int, int>> st;

public:
    MaxStack() {}

    void push(int x) {
        if (st.empty()) {
            st.push_back({x, x});
        } else {
            int _max = max(st.back().first, x);
            st.push_back({x, _max});
        }
    }

    int pop() {
        int val = st.back().first;
        st.pop_back(); 
        return val;
    }

    int top() {
        return st.empty() ? -1 : st.back().first;
    }

    int peekMax() {
        return st.empty() ? -1 : st.back().second;
    }

    int popMax() {
        int max_val = peekMax();
        vector<int> buffer;

        while(top() != max_val) {
            buffer.push_back(pop());
        }

        pop();

        while(!buffer.empty()) {
            push(buffer.back());
            buffer.pop_back();
        }

        return max_val;
    }
};
