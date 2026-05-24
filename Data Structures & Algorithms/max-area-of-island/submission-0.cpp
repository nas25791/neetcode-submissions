class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        int row = grid.size();
        int col = grid[0].size();

        int maxArea = 0;
        int area = 0;

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1){
                    area = dfs(grid, i, j);
                }

                if (area > maxArea) maxArea = area;

                area = 0;
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){

        int row = grid.size();
        int col = grid[0].size();

        //Basecase
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0){
            return 0;
        }

        grid[i][j] = 0; //sink it

        int area = 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) 
                    + dfs(grid, i, j+1) + dfs(grid, i, j-1);

        return area;
    }
};
