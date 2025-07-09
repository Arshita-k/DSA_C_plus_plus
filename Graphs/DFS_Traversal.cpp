// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&adj,vector<vector<int>>&edges)
{
    int numVertices=edges.size();
    for(int i=0;i<numVertices;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}

void dfs(vector<vector<int>>&adj,vector<int>&visited,int source)
{
    
    visited[source]=1;
    cout<<source<<" ";
        
    for(auto neighbor : adj[source])
    {
       if(visited[neighbor]==0)
       {
           dfs(adj,visited,neighbor);
       }
    }
    
}
int main() {
    
    int v=6;
    vector<vector<int>>adj(v);
    vector<vector<int>>edges{{0,1},{0,2},{0,3},{1,3},{1,4},{2,3},{3,4}};
    
    addEdge(adj,edges);
    vector<int>visited(v+1,0);
    cout<<" BFS Traversal "<<endl;
    dfs(adj,visited,0);

    return 0;
}
