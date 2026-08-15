#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int number_of_connected_components_in_an_undirected_graph(int n, vector<vector<int>>& edges) {
    if (edges.empty())
        return 0;
    
    unordered_set<int> seen;
    int rows = edges.size();
    int cols = edges[0].size();
    int connected = 0;
    
    int last = 0;
    for (int r = 0; r < rows; r++) {
        for (int c : edges[r]) {
            if (c)
            last = max(last, c);
        }
    }
}

void ignore_line() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template<typename T>
vector<T> get_words() {
    string line;
    getline(cin, line);
    istringstream ss{line};
    ss >> boolalpha;
    vector<T> v;
    copy(istream_iterator<T>{ss}, istream_iterator<T>{}, back_inserter(v));
    return v;
}

int main() {
    int n;
    cin >> n;
    ignore_line();
    int edges_length;
    cin >> edges_length;
    ignore_line();
    vector<vector<int>> edges;
    for (int i = 0; i < edges_length; i++) {
        edges.emplace_back(get_words<int>());
    }
    int res = number_of_connected_components_in_an_undirected_graph(n, edges);
    cout << res << '\n';
}
