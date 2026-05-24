class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        
        int islandcnt = 0;
 
        for (int i = 0 ; i < row; i++){
            for (int j = 0; j < col; j++){
                // if we find land dfs
                if (grid[i][j] == '1'){
                    islandcnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return islandcnt;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();

        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j]=='0'){
            return;
        }

        grid[i][j] = '0'; //sink it as already visited

        dfs(grid, i-1,j);
        dfs(grid, i+1,j);
        dfs(grid, i,j-1);
        dfs(grid, i,j+1);
    }

};
