#include<bits/stdc++.h>
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') //Boundary check (0 is water) (Rest are Matrix boundaries)
            return;
        grid[i][j]='0'; //Visiting island (Can be considered as sunken as we visit it)
        //4 Recursive DFS call for traverals across all the 4 directions discussed in the question
        dfs(grid,i+1,j,m,n); // Check down
        dfs(grid,i-1,j,m,n); // Check up
        dfs(grid,i,j+1,m,n); // Check right
        dfs(grid,i,j-1,m,n); // Check left
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ctr=0; //counter variable to count isolated islands
        //Traversing through mxn matrix
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //Spotting islands 
                if(grid[i][j]=='1')
                ctr+=1;
                dfs(grid,i,j,m,n); //Calling the DFS function the moment we find a possible island
            }
        }
        //Return counter after finding all the possible isolated islands
        return ctr;
    }
};