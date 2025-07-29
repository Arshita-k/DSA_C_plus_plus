#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>&vis,vector<vector<int>>&adj,int node)
{
    vis[node]=1;
    
    for(auto neighbor : adj[node])
    {
        if(vis[neighbor]==0)
            dfs(vis,adj,neighbor);
    }
}
int numofProvinces(int V,vector<vector<int>>&adj)
{
    vector<int>vis(V,0);
    int count=0;
    for(int i=1;i<V;i++)
    {
        if(vis[i]==0)
        {
            count++;
            dfs(vis,adj,i);
        }
    }
    return count;
}
int main()
{
    vector<vector<int>>edges={{1,2},{2,3},{4,5},{5,6},{7,8}};
    int V=9;
    //adjacency list
    vector<vector<int>>adj(V);
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    //number of provinces
    cout<<numofProvinces(V,adj);
    return 0;

}
