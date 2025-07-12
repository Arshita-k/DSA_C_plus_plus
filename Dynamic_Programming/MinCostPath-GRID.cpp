
//minCost(cost, m, n) = cost[m][n] + min(minCost(cost, m, n-1), minCost(cost, m-1, n), minCost(cost, m-1, n-1))
#include <bits/stdc++.h>
using namespace std;
int findMinCost(vector<vector<int>>&cost,int rows,int cols,vector<vector<int>>&memo)
{
    if(rows==0 && cols==0) return cost[0][0];
    
    if(rows<0 || cols<0) return 1e9; //out of bounds to skip this path
    if(memo[rows][cols]!=-1) return memo[rows][cols]; 
    
    int up=findMinCost(cost,rows-1,cols,memo);
    int left=findMinCost(cost,rows,cols-1,memo);
    //if diagonal allowed
    //int diag=cost[rows][cols]+findMinCost(cost,rows-1,cols-1,memo);
    
    return memo[rows][cols]=cost[rows][cols]+min(up,left);
    
}
int main() {
    
    vector<vector<int>>cost={{ 1,3,1 },{ 1, 5, 1 },{4,2,1} };
    int rows=cost.size();
    int cols=cost[0].size();
    vector<vector<int>>memo(rows,vector<int>(cols,-1));
    //Memoization top down (m,n) to (0,0)
    cout<<"Memoization ";
    cout<<findMinCost(cost,rows-1,cols-1,memo)<<endl;
    
     //Tabulation bottom up (0,0) to (m,n)
    vector<vector<int>>dp(rows,vector<int>(cols,-1));
    dp[0][0]=cost[0][0];
    
    
    // Fill the first row (can only come from the left)
    for (int j = 1; j < rows; ++j) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }

    // Fill the first column (can only come from above)
    for (int i = 1; i < cols; ++i) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }

    // Fill the rest of the DP table
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) 
        {
            dp[i][j] = cost[i][j] + min({dp[i - 1][j], dp[i][j - 1]});
        }
    }

    // The result is the minimum cost to reach the bottom-right cell
    cout<<"Tabulation ";
    cout<<dp[rows - 1][cols - 1];
    return 0;
}
