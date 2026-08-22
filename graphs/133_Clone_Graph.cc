#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
    // Create a hashmap to track visited and unvisited nodes efficiently
    // in order to avoid infinite looping since its and undirected graph
    unordered_map<Node*, Node*> visited;

    // Use DFS alongside the adjancency list of the graph to recursively 
    // visit the nodes and neighbours of each node while creating a deep
    // copy as we go
    Node* dfs(Node* node) {
        // create a new node adress in memory and set it to the value of
        // the current node we're evaluating
        Node* clone = new Node(node->val);

        // update the hashmap to indicate this node has been visited and
        // cloned
        visited[node] = clone;

        // Go through the neighbours of the current node being evaluated
        // and recursively clone and update the hashmap
        for (auto& n : node->neighbors) {
            // if this neighbour hasnt been visited, we use DFS to visit
            // it & its neighbours recursively while updating the hashmap
            if (visited.find(n) == visited.end()) {
                dfs(n);
            }
            // Now that we have guaranteed this specific neighbor has been 
            // cloned (either from a previous visit or the recursive call 
            // we just made), we add it to the current clone's neighbor list.
            clone->neighbors.push_back(visited[n]);
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};