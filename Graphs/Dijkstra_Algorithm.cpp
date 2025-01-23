#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // Infinity

// Edge structure to store vertices and their costs
struct Edge {
    int vertex, weight;
};

// Comparator for the priority queue
bool operator>(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

// Dijkstra's Algorithm function
vector<int> dijkstra(int source, int vertices, vector<vector<Edge>>& adjList) {
    vector<int> dist(vertices, INF); // Distance from source to each vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue; // Ignore outdated distance

        for (const Edge& e : adjList[u]) {
            int v = e.vertex;
            int w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 5; // Number of vertices
    vector<vector<Edge>> adjList(vertices);

    // Add edges
    adjList[0].push_back({1, 10});
    adjList[0].push_back({4, 3});
    adjList[1].push_back({2, 2});
    adjList[1].push_back({4, 4});
    adjList[2].push_back({3, 9});
    adjList[3].push_back({2, 7});
    adjList[4].push_back({1, 1});
    adjList[4].push_back({2, 8});

    int source = 0;
    vector<int> distances = dijkstra(source, vertices, adjList);

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << "\t" << distances[i] << endl;
    }

    return 0;
}
