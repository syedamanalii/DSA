#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

vector<int> topologySort(vector<vector<int>> &edges, int v, int e) {
    // Create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Find all indegrees
    vector<int> indegree(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // 0 indegree waalo ko kro push
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Do BFS
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}

int main() {
    int v = 6; // number of vertices
    int e = 6; // number of edges
    vector<vector<int>> edges = {{5, 0}, {4, 0}, {5, 2}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topologySort(edges, v, e);
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}
