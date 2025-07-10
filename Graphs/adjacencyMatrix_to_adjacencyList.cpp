// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>&isConnected,vector<vector<int>>&adj)
{
    int N=isConnected.size();
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(isConnected[i][j]==1 && i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
                //count+=1;
            }
        }
    }
    //return count==0 ? N:count;
}

int main() {
    
    vector<vector<int>>isConnected={{1,0,0},{0,1,0},{0,0,1}};
    int V=isConnected.size();
    vector<vector<int>>adj(V);
    cout<<addEdge(isConnected,adj);
    return 0;
}
