#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adjList[],int visited[],vector<int>&list)
{
    visited[node]=1;
    list.push_back(node);
    for(auto it: adjList[node])
    {
        if(!visited[it])
        {
            dfs(it,adjList,visited,list);
        }
    }
}
vector<int>DFS(int n,vector<int>adjList[],int initial)
{
    int visited[n]={0};
    vector<int>list;
    dfs(initial,adjList,visited,list);
    return list;
}
void addEdge(vector<int>adjList[],int u,int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
void print(vector<int>&adj)
{
    int i=0;
    while(i<adj.size())
    {
        cout<<adj[i]<<" ";
        i++;
    }
}
int main()
{
    vector<int>adjList[6];
    addEdge(adjList,1,2);
    addEdge(adjList,1,5);
    addEdge(adjList,2,5);   
    addEdge(adjList,2,3);
    addEdge(adjList,5,3);
    addEdge(adjList,5,4);
    addEdge(adjList,3,4);
    vector<int>result=DFS(6,adjList,3);
    print(result);
    return 0;
}
    
