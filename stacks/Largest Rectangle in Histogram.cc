#include <bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    st.push(-1);
    int area = 0;

    for (int i = 0; i < heights.size(); i++) {
        while(st.top() != -1 && heights[i] <= heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int w = i - st.top() - 1;
            area = max(area, h * w);
        }
        st.push(i);
    }

    while(st.top() != -1) {
        int h = heights[st.top()];
        st.pop();
        int w = heights.size() - st.top() - 1;
        area = max(area, h * w);
    }

    return area;
}

int main() {
    vector<int> heights = {2,4};
    int output = largestRectangleArea(heights);

    cout << output << endl;
    return 0;
}