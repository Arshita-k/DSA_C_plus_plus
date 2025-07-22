
#include <bits/stdc++.h>
using namespace std;

int FrogJump(int n,vector<int>&arr,vector<int>&dp)
{
    if(n==0) return 0; 
    if(dp[n]!=-1) return dp[n];
    
    int jumpTwo=INT_MAX;
    int jumpOne=FrogJump(n-1,arr,dp)+abs(arr[n]-arr[n-1]);
    if(n>1);
        jumpTwo=FrogJump(n-2,arr,dp)+abs(arr[n]-arr[n-2]);
    
    return dp[n]=min(jumpOne,jumpTwo);
        
}
int main() {
    
    //vector<int>arr={10,20,30,10};
    vector<int>arr1={30,10,60,10,60,50};
    //vector<int>arr2={10,40,30,20};
    int N=arr1.size();
    vector<int>dp(N,-1);
    cout<<FrogJump(N-1,arr1,dp);
    return 0;
}
