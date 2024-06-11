#include <bits/stdc++.h>
using namespace std;
//fibonnaci series 0 1 1 2 3 5 8 13......
// 0th term 0   1st term 1 
// f(n)=f(n-1)+f(n-2)

//Memoization using recursion
int fib(int n,vector<int>& dp)
{
    //base condition
    if(n==0)
       return 0;
    if(n==1)
       return 1;
    //check previous funtion value
    if(dp[n]!=-1)
       return dp[n];
    
    //store value in array
    return dp[n]= fib(n-1,dp) + fib(n-2,dp);

}

int main()
{
    int num,n;
    cout<<"Enter Nth term : ";
    cin>>num;
    vector<int> dp(num+1,-1);
  //Tabulation start
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n;i++)
    {
      dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
  //Tabulation end
    //recursive call for memization
  //optimised solutiom
    int prev2=0,prev1=1;
    for(int i=2;i<=num;i++)
    {
      int crr = prev1 + prev2;
      prev1 = crr;
      prev2=prev1;
    }
    cout<<prev1;
   //recursive call for memization
    cout<<"Number is : "<<fib(num,dp);
    return 0;
}
