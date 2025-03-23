#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Function to perform BFS and print all reachable nodes
void BFS(int start, unordered_map<int, vector<int>>& adj, int n) {
    // To keep track of visited nodes
    vector<bool> visited(n, false); 
    
    // Queue for BFS
    queue<int> q;
    
    // Start BFS from the given start node
    visited[start] = true;
    q.push(start);

    cout << "Nodes reachable from node " << start << ": ";
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Traverse all adjacent nodes
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // Number of nodes and edges
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Adjacency list to store the graph
    unordered_map<int, vector<int>> adj;

    cout << "Enter edges (format: u v, meaning u -> v):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;

        // Ensure u and v are within the valid node range
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            adj[v].push_back(u); // Uncomment this for an **undirected** graph
        } else {
            cout << "Invalid edge (" << u << ", " << v << "). Skipping." << endl;
        }
    }

    // Starting node for BFS
    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    // Check if the starting node is within the valid range
    if (start >= 0 && start < n) {
        // Perform BFS from the start node
        BFS(start, adj, n);
    } else {
        cout << "Invalid starting node." << endl;
    }

    return 0;
}
