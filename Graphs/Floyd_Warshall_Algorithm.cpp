#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void floyd_warshall(int vertices, std::vector<std::vector<int>>& graph) {
    // Distance matrix
    std::vector<std::vector<int>> dist = graph;

    // Floyd-Warshall algorithm
    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < vertices; ++i) {
        if (dist[i][i] < 0) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    // Print shortest distance matrix
    std::cout << "Shortest distances between every pair of vertices:" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (dist[i][j] == INF)
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int vertices = 4;
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floyd_warshall(vertices, graph);

    return 0;
}
