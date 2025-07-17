// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void addEdges(vector<vector<int>>&adj,vector<vector<int>>&edges)
{
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        //cout<<edge[0]<<"->"<<edge[1]<<endl;
    }
}
void TopologicalSortingBFS(vector<vector<int>>&adj,int V)
{
    vector<int>indegree(V);
    for(int i=0;i<V;i++)
    {
        for(auto it: adj[i])
        {
            indegree[it]++;
            //cout<<it<<" ";
        }
    }
    cout<<endl;
    queue<int>q;
    // Queue to store vertices with indegree 0
    //hence vertices with dependecy zero
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);//need to print them first
        }
    }
    //add vertices connected to them next and print them 
    while(q.empty()==0)
    {
        int current_node=q.front();
        q.pop();
        cout<<current_node<<" ";
        for(auto neighbor : adj[current_node])
        {
            indegree[neighbor]--; 
            //  If indegree becomes 0, push it to the queue
            if(indegree[neighbor]==0)
            {
                q.push(neighbor);
            }
        }
    }
}
void SortUtil(int i,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st)
{
    vis[i]=1;
    for(int neighbor : adj[i])
    {
        if(vis[neighbor]==0)
            SortUtil(neighbor,adj,vis,st);
    }
    st.push(i);
}
void TopologicalSortingDFS(vector<vector<int>>&adj,int V)
{
    stack<int>st;
    vector<int>vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            SortUtil(i,adj,vis,st);
        }
    }
    
    while(st.empty()==0)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
int main() {
    
    vector<vector<int>>edges={{5,0},{4,0},{5,2},{4,1},{2,3},{3,1}};
    int V=6;
    vector<vector<int>>adj(V);
    addEdges(adj,edges);
    //Togological sorting in other ways dependency order
    
    //bfs or Kahn's Algorithm
    TopologicalSortingBFS(adj,V);
    cout<<endl;
    //dfs
    TopologicalSortingDFS(adj,V);
    return 0;
}
