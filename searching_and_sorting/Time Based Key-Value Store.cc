#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> structure;

    string b_search(vector<pair<string, int>>& container, int timestamp) {
        int l = 0, r = container.size()-1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (container[mid].second == timestamp) {
                return container[mid].first;
            } else if (container[mid].second > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (r >= 0) return container[r].first;
        else return "";
    }

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        structure[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (structure.find(key) == structure.end()) return "";
        return b_search(structure[key], timestamp);
    }
};