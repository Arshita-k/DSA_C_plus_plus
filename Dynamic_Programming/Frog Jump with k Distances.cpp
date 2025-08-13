#include <bits/stdc++.h>
using namespace std;

int findSteps(int n,int k,vector<int>&arr,vector<int>&dp)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(n-j>=0) //ensure we do not cross boundary
        {
            int jump=findSteps(n-j,k,arr,dp)+abs(arr[n]-arr[n-j]);
            minSteps=min(jump,minSteps);
        }
    }
    return dp[n]=minSteps;
    
}
int main() {
    
    int n=6, k=2;
    //at each step we would have k choices need to find the miminum cost taken
    vector<int>arr{30,10,60,10,60,50};
    vector<int>dp(n,-1);
    //Memoization
    cout<<findSteps(n-1,k,arr,dp);
    return 0;
}
        
           
