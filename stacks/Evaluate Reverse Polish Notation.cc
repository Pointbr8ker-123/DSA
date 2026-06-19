#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> track;
    
    for (string c : tokens) {
        if (c == "+") {
            int sec = track.top(); track.pop();
            int fir = track.top(); track.pop();
            track.push(fir + sec);
        } else if (c == "-") {
            int sec = track.top(); track.pop();
            int fir = track.top(); track.pop();
            track.push(fir - sec);
        } else if (c == "*") {
            int sec = track.top(); track.pop();
            int fir = track.top(); track.pop();
            track.push(fir * sec);
        } else if (c == "/") {
            int sec = track.top(); track.pop();
            int fir = track.top(); track.pop();
            track.push(fir / sec);
        } else {
            track.push(stoi(c));
        }
    }
    return track.top();
}

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    int output = evalRPN(tokens);

    cout << output << endl;
}