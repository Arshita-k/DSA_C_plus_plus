// C++ code to find number of unique paths
// using Memoization
#include <bits/stdc++.h>
using namespace std;

// Helper function to find unique paths
int uniquePathsRecur(int i, int j, vector<vector<int>>& grid, 
vector<vector<int>>& memo) {
    int r = grid.size(), c = grid[0].size();
    
    // If out of bounds, return 0
    if(i == r || j == c) {
        return 0;
    }
    
    // If cell is an obstacle, return 0
    if(grid[i][j] == 1) {
        return 0;
    }
    
    // If reached the bottom-right cell, return 1
    if(i == r-1 && j == c-1) {
        return 1;
    }
    
    // If already computed, return the stored result
    if(memo[i][j] != -1) {
        return memo[i][j];
    }
    
    // Compute and store the result
    memo[i][j] = uniquePathsRecur(i+1, j, grid, memo) + 
                 uniquePathsRecur(i, j+1, grid, memo);
    
    return memo[i][j];
}

// Function to find unique paths with obstacles
int uniquePaths(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    
    // Initialize memoization table with -1
    vector<vector<int>> memo(n, vector<int>(m, -1));
    
    return uniquePathsRecur(0, 0, grid, memo);
}

int main() {
    vector<vector<int>> grid = {
        { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 }
    };
    
    cout << uniquePaths(grid);
    
    return 0;
}
