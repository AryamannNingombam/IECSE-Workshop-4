class Solution {
public:
// dfs function= traverses the entire island and replaces it's 1's with 0s using recursion
void dfs(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '0';   // mark it as visited or sunken
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};   // displacement arrays used to simplify the directions as we code the solution
    for (int k = 0; k < 4; k++) {
        // for all the four directions : check if there is a connecting 1
        int m = i + dx[k];
        int n = j + dy[k];
        if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n] == '1') {
            // if they are within the boundaries
            dfs(grid, m, n);
        }
    }
}

// main function
int numIslands(vector<vector<char>> &grid) {
    int count = 0;  // ans
    // loop for traversing through the entire island
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                // implies it is a univisted part of island
                count++;
                // Here we call DFS function to traverse the entire island
                dfs(grid, i, j);
            }
        }
    }
    return count;
}
};