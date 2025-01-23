#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max(); // Infinity

struct Edge {
    int source, dest, weight;
};

void bellman_ford(int vertices, int edges, int source, std::vector<Edge>& graph) {
    std::vector<int> dist(vertices, INF);
    dist[source] = 0;

    // Relax edges (vertices - 1) times
    for (int i = 1; i <= vertices - 1; ++i) {
        for (int j = 0; j < edges; ++j) {
            int u = graph[j].source;
            int v = graph[j].dest;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edges; ++j) {
        int u = graph[j].source;
        int v = graph[j].dest;
        int w = graph[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    // Print the computed shortest distances
    std::cout << "Vertex\tDistance from Source" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << "\t";
        if (dist[i] == INF)
            std::cout << "INF" << std::endl;
        else
            std::cout << dist[i] << std::endl;
    }
}

int main() {
    int vertices = 5; // Number of vertices
    int edges = 8;    // Number of edges
    std::vector<Edge> graph(edges);

    // Add edges (source, destination, weight)
    graph[0] = {0, 1, -1};
    graph[1] = {0, 2, 4};
    graph[2] = {1, 2, 3};
    graph[3] = {1, 3, 2};
    graph[4] = {1, 4, 2};
    graph[5] = {3, 2, 5};
    graph[6] = {3, 1, 1};
    graph[7] = {4, 3, -3};

    int source = 0; // Source vertex
    bellman_ford(vertices, edges, source, graph);

    return 0;
}
