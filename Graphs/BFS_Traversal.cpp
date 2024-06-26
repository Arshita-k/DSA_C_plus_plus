#include <bits/stdc++.h>
using namespace std;
vector<int>BFS(int n,vector<int>adjList[],int initial)
{
    int visited[n]={0}; //to keep track of vertices visited
    visited[initial]=1; //start with intial node
    queue<int>Q; //For computing 
    vector<int>answer; //For dtoring BFS traversal
    Q.push(initial); 

    while(!Q.empty()) //traverse till all the nodes are visited
    {
        int vertex=Q.front();
        Q.pop();
        answer.push_back(vertex); //store it in a solution array
        for(auto it : adjList[vertex])
        {
            if(!visited[it]) //if vertex is not visited 
            {
                visited[it]=1;
                Q.push(it);
            }
        }
    }
    return answer;
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
    vector<int>result=BFS(5,adjList,3);
    print(result);
    return 0;
}
    
