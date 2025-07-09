#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge between two vertices
void addEdge(vector<vector<int>>&adj,vector<vector<int>>&edges) {
    
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; // Print the vertex
        for (int j : adj[i]) {
            cout << j << " "; // Print its adjacent
        }
        cout << endl; 
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices and no edges
    int V = 6;
    vector<vector<int>> adj(V);
    vector<vector<int>> edges={{1,2},{2,4},{3,2},{3,1},{4,1},{4,5},{5,3}};
    addEdge(adj,edges);
    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}
