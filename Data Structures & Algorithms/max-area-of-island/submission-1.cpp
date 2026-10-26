class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int row=0; row<grid.size();++row){
            for(int col=0; col<grid[0].size(); ++col){
                if(grid[row][col] == 1){
                    ans = max(ans, dfs(grid, row, col));
                }
            }
        }
        return ans;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c){

        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) return 0;

        if(grid[r][c] != 1) return 0; // either water or visited

        grid[r][c] = 0; // mark visited

        return 1
                +dfs(grid, r-1, c)
                +dfs(grid, r+1, c)
                +dfs(grid, r, c-1)
                +dfs(grid, r, c+1);

    }
};
