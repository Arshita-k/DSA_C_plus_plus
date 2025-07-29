#include <bits/stdc++.h>
using namespace std;

string CourseSchedule(int V,vector<vector<int>>&adj)
{
    vector<int>indegree(V,0);
    vector<int>order;
    for(int i=0;i<V;i++)
    {
        for(int edge : adj[i])
        {
            indegree[edge]++;
        }
    } 
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0) 
            q.push(i);
    }
    
    while(!q.empty())
    {
        int curr_node=q.front();
        q.pop();
        order.push_back(curr_node);
        
        for(auto neighbor : adj[curr_node])
        {
            indegree[neighbor]--;
            if(indegree[neighbor]==0)
                q.push(neighbor);
        }
    }
    
    //return order
    if(order.size()==V) return "true";
    //return empty array
    return "false";
    
}
int main()
{
    vector<vector<int>>edges={{1,2},{4,3},{2,4},{4,1}};
    int V=5;
    //adjacency list
    vector<vector<int>>adj(V);
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    
    //course schedule -1
    //Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks also return the order of tasks you should pick to finish all tasks
    cout<<CourseSchedule(V,adj);
    
    return 0;

}
