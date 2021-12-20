class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //Approach : BFS 

        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int days = 0 , total = 0, cnt = 0;
        
        queue<pair<int, int>>rotten;  // pair for storing co-ordinates (i, j)

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j] != 0) total++; // counting total oranges
                if(grid[i][j] == 2) rotten.push({i, j});  // pushing all rotten oranges to the queue.
            }
        }
        
        int dx[4] = {0 , 0 , 1, -1};  //direction vectors (for cleaner implementation)
        int dy[4] = {1 , -1 , 0 , 0}; // direction vectors
        
        while(!rotten.empty()){
            int k = rotten.size(); //number of current rotten oranges
            cnt += k; // adding to current count
            while(k--){
                int x = rotten.front().first; //position
                int y = rotten.front().second; //position
                rotten.pop();
                
                for(int i = 0 ; i < 4; i++){  //checking for all four possible directions adjacnt to the rotten orange
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n||grid[nx][ny] != 1) continue; //if no rotten orange or boundary adjacent to the orange we do nothing.
                    grid[nx][ny] = 2; //if orange is present we rot it :)
                    rotten.push({nx, ny}); //pushing the newly rotten orange to the queue
                }
            }
            if(!rotten.empty()) days++; // all of the rotten oranges of this day have done their job 
        }
        return total == cnt? days : -1; //if our current rotten oranges is not equal to the total number of oranges in the graph, it means some oranges were left.
    }
};