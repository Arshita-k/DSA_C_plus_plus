// find the shortest path from the source to all other nodes in this graph. The source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&edges,vector<vector<int>>&adj)
{
    for(auto edge : edges)
    {
        //undirected graph so path is two way
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
}
void bfs(vector<vector<int>>&adj, int src,vector<int>&dist, vector<int>&ans)
{
    queue<int>q;
    dist[src]=0;
    q.push(src);
    
    while(q.empty()==0)
    {
        int current_node=q.front();
        q.pop();
        for(auto neighbor : adj[current_node])
        {
            if(dist[current_node]+1<dist[neighbor])
            {
                dist[neighbor]=1+dist[current_node];
                q.push(neighbor);
            }
        }
    }
    
    for(int i=0;i<adj.size();i++)
    {
        if(dist[i]!=1e9)
        {
            ans[i]=dist[i];
        }
    }
    for(auto it : ans) cout<<it<<" ";
}
int main() {
    
    vector<vector<int>>edges={{0,1},{0,3},{1,2},{2,6},{3,4},{4,5},{5,6},{6,7},{6,8},{7,8}};
    int V=9;
    vector<vector<int>>adj(V);
    addEdge(edges,adj);
    //shortest path using bfs 
    vector<int>dist(V,1000);
    vector<int>ans(V,-1);
    
    //standard bfs traversal
    bfs(adj,0,dist,ans);
    return 0;
}
