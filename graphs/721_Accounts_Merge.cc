#include <bits/stdc++.h>
using namespace std;

// Create the DisjointSet/Union Find Data Structure
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        // Path compression
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by Rank
    void unite(int a, int b) {
        int root_a = find(a), root_b = find(b);
        if (root_a == root_b) return;

        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else {
            parent[root_b] = root_a;
            rank[root_a]++;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_to_id;
        unordered_map<string,string> email_to_name;
        int id{};

        // Iterate through the "accounts" array to populate the hashmaps above
        for (const auto &account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                email_to_id[email] = id++;
                email_to_name[email] = name;
            }
        }

        // Use the Disjoint Set to track emails of the same account
        DisjointSet ds(id);
        for (const auto &account : accounts) {
            for (int i = 2; i < account.size(); i++) {
                int id_a = email_to_id[account[i-1]];
                int id_b = email_to_id[account[i]];
                ds.unite(id_a, id_b);
            }
        }

        // Create a hashmap that tracks the parent/root ids of every email so we can
        // trace them back to the distinct owner of all the related emails
        unordered_map<int, vector<string>> groups;
        for (const auto &pair : email_to_id) {
            string email = pair.first;
            int id = pair.second;
            int root_id = ds.find(id);
            groups[root_id].push_back(email);
        }

        // Extract the related emails from "groups" and map join them in a single
        // array with the name of the owner (gotten from  "email_to_name") to arrive
        // at the final answer
        vector<vector<string>> ans;
        for (const auto &pair : groups) {
            vector<string> emails = pair.second;
            sort(emails.begin(), emails.end());

            string name = email_to_name[emails[0]];
            emails.insert(emails.begin(), name);

            ans.push_back(emails);
        }
        return ans;
    }
};