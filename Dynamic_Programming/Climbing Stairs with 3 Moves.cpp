#include <bits/stdc++.h>
using namespace std;
int HelperCount(vector<int>&dp,int n)
{
    if(n<0) return 0;
    if(n==0||n==1) return 1;
    if(dp[n]!=0) return dp[n];
    //can only take 1/2/3 steps at a time
    dp[n]=HelperCount(dp,n-1)+HelperCount(dp,n-2)+HelperCount(dp,n-3);
    
    return dp[n];
}
int countWays(int n)
{
    vector<int>dp(n+1,0);
    return HelperCount(dp,n);
}
int main() {
    
    int num;
    cout<<"Enter number of stairs to climb "<<endl;
    cin>>num;
    //Memoization Call - top down (n to 0/1/less than 1)
    cout<<"Memoization "<<countWays(num)<<endl;
   
    
    //Tabulation - Bottom up (0/1/2 to n)
    vector<int>dp(num+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=num;i++)
    {
        //can only take 1/2/3 steps at a time
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<"Tabulation "<<dp[num];
    return 0;
}
