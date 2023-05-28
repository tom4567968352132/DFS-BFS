#include <iostream>
#include <climits>

using namespace std;

#define V 5 // Number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int minIndex, minValue = INT_MAX;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minValue) {
            minValue = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int v = 1; v < V; v++) {
        cout << parent[v] << " - " << v << "\t" << graph[v][parent[v]] << endl;
    }
}

// Function to find the MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // Set to track vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start with the first vertex
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true;            // Include the picked vertex in MST

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
