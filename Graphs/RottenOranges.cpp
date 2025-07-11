// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1

//0 means cell is empty, 1 means cell has fresh orange whereas 2 means rotten orange
#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    queue<pair<int,int>>track; //to track coordiantes of rotten oranges
    int totalFresh=0,days=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j]==2)
            {
                track.push({i,j});
            }
            if(grid[i][j]==1)
            {
                totalFresh++;
            }
        }
    }
    if(totalFresh==0) return 0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    while(!track.empty())
    {
        int queue_size=track.size(); //Get the number of rotten oranges at the current time level
        bool rottedInThisMinute = false; // Flag to track if any orange rotted in this minute
        for(int  k=0;k<queue_size;k++)
        {
            // Process all oranges from the current level
            int x=track.front().first;
            int y=track.front().second;
            track.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=rows || ny>=cols || nx<0 || ny<0 || grid[nx][ny]!=1)
                {
                    continue;
                }
                grid[nx][ny]=2;
                track.push({nx,ny});
                totalFresh--;
                rottedInThisMinute=true;
            }
        }
        if(rottedInThisMinute)
            days++;
    }
    return totalFresh==0?days:-1;
}
int main() {
    vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
    cout<< orangesRotting(grid);
    return 0;
}
