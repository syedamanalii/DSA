#include <vector>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    // Initialize adjacency list
    vector<vector<int>> adj(n);

    // Fill adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add the edge to the adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Add self-loop to each node (if needed)
    for (int i = 0; i < n; i++) {
        adj[i].insert(adj[i].begin(), i);
    }

    return adj;
}
