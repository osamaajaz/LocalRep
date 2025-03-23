#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

// Function to find the parent of a node (with path compression)
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]); 
    return parent[i];
}

// Function to unite two subsets (Union by Rank)
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Kruskal's Algorithm to find the Minimum Spanning Tree (MST)
void kruskal(int V, vector<pair<int, pair<int, int>>>& edges) {
    vector<pair<int, pair<int, int>>> result; // {weight, {u, v}}
    int parent[V], rank[V];

    // Initialize parent and rank arrays
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end());

    int minCost = 0; // Total cost of MST

    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Check if adding this edge creates a cycle
        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, rank, u, v);
            result.push_back({weight, {u, v}});
            minCost += weight;
        }
    }

    // Print the edges in the MST
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (auto& edge : result)
        cout << edge.second.first << " -- " << edge.second.second << " == " << edge.first << endl;
    
    cout << "Minimum cost of MST: " << minCost << endl;
}

int main() {
    int V = 4; // Number of vertices

    // Define edges in the form {weight, {u, v}}
    vector<pair<int, pair<int, int>>> edges = {
        {10, {0, 1}},
        {6, {0, 2}},
        {15, {1, 3}},
        {4, {2, 3}},
        {5, {1, 2}}
    };

    kruskal(V, edges);

    return 0;
}
