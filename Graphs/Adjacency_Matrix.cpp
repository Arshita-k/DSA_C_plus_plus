#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter number of Nodes/Vertices : ";
    cin>>n;
    cout<<"Enter number of Edges : ";
    cin>>m;
    //considering its 1 based indexing
    int adj[n+1][n+1]={0}; //Space comlexity n*n
    //adjacency matrix
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin<<a<<b;
        adj[a][b]=1; //its a undirected graph
        adj[b][a]=1;      //if it was a directed graph then order matters  
    }
    return 0;
}
