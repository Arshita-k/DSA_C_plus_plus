#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // Represents infinity

// Structure to represent an edge from one node to another with a weight
struct Edge {
    int to;      // Destination node
    int weight;  // Cost to reach 'to' from current node
};

// Dijkstra's algorithm to find shortest paths from 'source' to all other nodes
vector<int> dijkstra(int source, int n, vector<vector<Edge>>& graph) {
    vector<int> dist(n, INF);  // Distance from source to each node
    dist[source] = 0;

    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // Skip if we already found a better path
        if (currDist > dist[currNode]) continue;

        // Explore neighbors
        for (const Edge& edge : graph[currNode]) {
            int nextNode = edge.to;
            int weight = edge.weight;

            // Relaxation step
            if (dist[currNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;  // Number of nodes
    vector<vector<Edge>> graph(n);

    // Add directed edges: from → to with weight
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 3});
    graph[1].push_back({2, 2});
    graph[1].push_back({4, 4});
    graph[2].push_back({3, 9});
    graph[3].push_back({2, 7});
    graph[4].push_back({1, 1});
    graph[4].push_back({2, 8});

    int source = 0;
    vector<int> shortestDistances = dijkstra(source, n, graph);

    // Print results
    cout << "Node\tShortest Distance from Node " << source << "\n";
    for (int i = 0; i < n; ++i) {
        if (shortestDistances[i] == INF)
            cout << i << "\t" << "Unreachable\n";
        else
            cout << i << "\t" << shortestDistances[i] << "\n";
    }

    return 0;
}
