#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list> 
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component) {
    //answer stored in component
    component.push_back(node);
    //mark visited
    visited[node] = true; 

    // Recursively visit all the neighbors of the node
    for(auto i: adjList[node]) {
        if(!visited[i]) {
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> DFS(int v, int e, vector<vector<int>> &edges) {
    // Prepare adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    //For all nodes call DFS, if not visited
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    int v = 5;
    int e = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};

    vector<vector<int>> components = DFS(v, e, edges);

    // Print components
    for(auto component : components) {
        for(int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
