#include<bits/stdc++.h>
class Solution {
public:
    int dfs(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0')
            return 0;
        grid[i][j]='0';
        dfs(grid,i+1,j,m,n);
        dfs(grid,i-1,j,m,n);
        dfs(grid,i,j+1,m,n);
        dfs(grid,i,j-1,m,n);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ctr=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                ctr+=dfs(grid,i,j,m,n);
            }
        }
        return ctr;
    }
};