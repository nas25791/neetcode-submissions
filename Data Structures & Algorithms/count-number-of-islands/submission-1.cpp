class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.empty()) return 0;

        int no_of_island = 0;
        int rows = grid.size();
        int cols= grid[0].size();

        for (int i =0 ; i < rows; ++i){
            for (int j=0; j< cols; ++j){
                if (grid[i][j] == '1'){
                    no_of_island++;
                    dfs(grid, i, j);
                }
            }
        }
        return no_of_island;
    }

    void dfs(vector<vector<char>>& grid, int r , int c){
        int rows = grid.size();
        int cols = grid[0].size();

        //Boundary and water check
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0'){
            return;
        }

        //sink it
        grid[r][c] = '0';

        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};
