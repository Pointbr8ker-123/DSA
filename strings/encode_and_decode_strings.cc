#include <iostream>
#include <string>
#include <vector>
using namespace std;

string encode(vector<string>& strs) {
    string encoded = "";
    for (string& s : strs) {
        encoded += to_string(s.size()) + "#" + s;
    }
    return encoded;
}

vector<string> decode(string& s) {
    vector<string> decoded;

    int i = 0;
    while(i < s.size()) {
        int j = i;
        while(s[j] != '#') j++;
        
        int len = stoi(s.substr(i, j-i));
        
        i = j+1;

        decoded.push_back(s.substr(i, len));

        i += len;
    }
    return decoded;
}

int main() {
    vector<string> arr = {"hello", "world"};
    string encoded_message = encode(arr);
    cout << encoded_message << endl;

    vector<string> decoded_message = decode(encoded_message);
    for (string& s : decoded_message) cout << s << " ";
    cout <<  endl;

    return 0;
}