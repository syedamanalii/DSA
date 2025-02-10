#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
public:
    void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;
            
            //for undirected graph
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printAdj(unordered_map<int, list<int>> &adjList){
        for(auto i: adjList){
            cout << i.first << "->";
            for(auto j: i.second){
                cout << j << ",";
            }
            cout << endl;
        }
    }
    void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            //store FrontNode into ans
            ans.push_back(frontNode);

            //traverse all neighbours of frontNode
            for(auto neighbour: adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }

    vector<int> BFS(int vertex, vector<pair<int,int>> edges){
        unordered_map<int, list<int>> adjList;
        vector<int> ans;
        unordered_map<int, bool> visited;

        prepareAdjList(adjList, edges);
        printAdj(adjList);

        //traverse all components of a graph
        for(int i = 0; i < vertex; i++){
            if(!visited[i]){
                bfs(adjList, visited, ans, i);
            }
        }
        return ans;
    }
};
int main() {
    Graph g;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    int vertex = 4;

    vector<int> result = g.BFS(vertex, edges);
    cout << "BFS Traversal: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;               

    return 0;
}