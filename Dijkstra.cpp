#include <iostream>
#include <limits.h>
using namespace std;

int miniDist(int distance[], bool fin[]) // Finding the minimum distance
{
    int minimum = INT_MAX, ind = -1; // Initialize `ind` to -1

    for (int k = 0; k < 6; k++) {
        if (!fin[k] && distance[k] <= minimum) {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6], int src) // Adjacency matrix
{
    int distance[6]; // Array to calculate the minimum distance for each node
    bool fin[6]; // Boolean array to mark visited and unvisited nodes

    for (int k = 0; k < 6; k++) {
        distance[k] = INT_MAX;
        fin[k] = false;
    }

    distance[src] = 0; // Source vertex distance is set to 0

    for (int i = 0; i < 6; i++) {
        int m = miniDist(distance, fin);
        if (m == -1) break; // Break if no minimum distance is found (all reachable nodes are visited)

        fin[m] = true;

        for (int k = 0; k < 6; k++) {
            // Updating the distance of neighboring vertex
            if (!fin[k] && graph[m][k] && distance[m] != INT_MAX &&
                distance[m] + graph[m][k] < distance[k]) {
                distance[k] = distance[m] + graph[m][k];
            }
        }
    }

    cout << "Vertex\t\tDistance from Source Vertex\n";
    for (int k = 0; k < 6; k++) {
        cout << char('A' + k) << "\t\t\t" << distance[k] << endl; // Using A, B, C, D, E, F instead of 0,1,2,3,4,5
    }
}

int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    DijkstraAlgo(graph, 0);
    return 0;
}
