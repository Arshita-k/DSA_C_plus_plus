#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& adj, vector<pair<int, int>>& mstEdges) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    // vector<int> parent(V, -1); // To store MST edges
    pq.push({0, 0}); // {weight, node}
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;

        // if (parent[node] != -1) {
        //     mstEdges.push_back({parent[node], node}); // Store MST edge
        // }

        for (auto& itr : adj[node]) {
            int adjnode = itr[0];
            int edgeWt = itr[1];
            if (vis[adjnode] == 0) {
                pq.push({edgeWt, adjnode});
                // if (parent[adjnode] == -1 || edgeWt < wt) {
                //     parent[adjnode] = node; // Update parent
                // }
            }
        }
    }

    return sum;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {4, 2, 7}
    };

    vector<vector<vector<int>>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<pair<int, int>> mstEdges;
    int mstWeight = spanningTree(V, adj, mstEdges);

    // cout << "Minimum Spanning Tree Weight: " << mstWeight << "\n";
    // cout << "Edges in the MST:\n";
    // for (auto& edge : mstEdges) {
    //     cout << edge.first << " - " << edge.second << "\n";
    // }

    return 0;
}
