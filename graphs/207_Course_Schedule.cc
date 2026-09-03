#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adjList, vector<char>& visited, vector<char>& path) {
        visited[node] = path[node] = 1;

        for (int course : adjList[node]) {
            if (!visited[course]) {
                if (dfs(course, adjList, visited, path)) return true;
            } else if (path[course]) return true;
        }

        // if we finish a particular stack and find no cycles, then we set the "path" to false
        // (against the subsequent call stacks) and return false to indicate that there were
        // no cycles found within this branch of the graph
        path[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list to track nodes and how theyre connected
        // to each other

        // NB: This problem involves a directed graph, so the adjacency list
        // has to be that of a directed graph

        // Since we are looking out for dependency, and j depeneds on i in [i, j], 
        // then our adjacency list would look like j -> i;
        vector<vector<int>> adjList(numCourses);
        for (auto& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
        }

        // "visited" tracks the nodes that have been visited at all while "path"
        // tracks the nodes that have been visited within the current stack
        // i.e it helps detect if there is a cycle by checking if the already 
        // visited node has been visited before within the same recursive call stack
        vector<char> visited(numCourses, 0);
        vector<char> path(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adjList, visited, path)) return false;
            }
        }
        // if dfs return true, it means we found a cycle and therefore should return
        // false and vice versa
        return true;
    }
};