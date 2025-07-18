// find the shortest path from the source to all other nodes in DAG. The source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex. Weighted edges given
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&edges,vector<pair<int,int>>adj[])
{
    for(auto edge : edges)
    {
        //undirected graph so path is two way
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adj[u].push_back({v,wt});
    }
}
void toposort(int i,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&st)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        int v=it.first;
        if(vis[v]==0)
        {
            toposort(v,adj,vis,st);
        }
    }
    st.push(i);
}

void shortestpath(vector<pair<int,int>>adj[], int src)
{
    int V=6;
    stack<int>st;
    vector<int>vis(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
            toposort(i,adj,vis,st);
    }
    vector<int>dist(V,1e9);
    dist[src]=0;
    
    while(st.empty()==0)
    {
        int current_node=st.top();
        st.pop();
        
        for(auto neighbor : adj[current_node])
        {
            int v=neighbor.first;
            int wt=neighbor.second;
            
            if(dist[current_node]+wt<dist[v])
                dist[v]=wt+dist[current_node];
        }
    }
    
    for(int i=0;i<V;i++)
    {
        if(dist[i]==1e9) cout<<-1<<" ";
        else cout<<dist[i]<<" ";
    }
    
}
int main() {
    
    vector<vector<int>>edges={{0,1,2},{0,4,1},{1,2,3},{2,3,6},{5,3,1},{4,5,4},{4,2,2}};
    int V=6;
    vector<pair<int,int>>adj[V];
    addEdge(edges,adj);
    //shortest path using topological sorting dfs 
    shortestpath(adj,0);
    return 0;
}
