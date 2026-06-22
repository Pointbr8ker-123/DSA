#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> highFive(vector<vector<int>>& items) {
    int k = 5;
    // create a hash map that stores the id of the student as the key
    // and a priority queue that stores the top 5 scores of the student
    // as the value of said key.
    unordered_map<int, 
                  priority_queue<int, vector<int>, greater<int>>> umap;

    // iterate through the items in the "items" vector to input the items
    // in the hashmap
    for (auto& item : items) { //  O(n)
        int id = item[0];
        int score = item[1];

        // for each key(i.e id) push the values(score) into the priority queue
        // (i.e min heap) and then we pop any score that's not in the top 5
        umap[id].push(score); // O(log k)
        if (umap[id].size() > k) {
            umap[id].pop();
        }
    } // O(n log k) = O(n) since k is constant i.e 5

    // we create a fresh vector for the final answer
    vector<vector<int>> ans;

    // we iterate through the hash map and extract the id and the top 5 scores
    // of each student; we use a while loop to calculate the sum of the scores
    // while popping at the same time.
    for (auto& [id, mh] : umap) { // O(no. of ids), say O(m)
        int sum = 0;
        while (!mh.empty()) { // O(k)
            sum += mh.top();
            mh.pop();
        }
        // we finally push the extracted id and sum into the answer vector and 
        // divide the sum by 5
        ans.push_back({id, sum/k});
    } // i.e total of O(m)
    
    // we sort the vector by id
    sort(ans.begin(), ans.end()); // O(m log m)
    return ans;
}