#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Since the graph is undirected, add v to w’s list.
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        
        // Start DFS from the first vertex with an edge
        int i;
        for (i = 0; i < V; i++) {
            if (!adj[i].empty()) {
                break;
            }
        }

        // If there are no edges in the graph, it's considered connected
        if (i == V) {
            return true;
        }

        DFSUtil(i, visited);

        // Check if all non-isolated vertices are visited
        for (int i = 0; i < V; i++) {
            if (!visited[i] && !adj[i].empty()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    if (g.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}