class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int row=0; row<grid.size();++row){
            for(int col=0; col<grid[0].size(); ++col){
                if(grid[row][col] == 1){
                    int count = 0;
                    dfs(grid, row, col, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& ans){
        
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return;

        if(grid[row][col] != 1) return; // either water or visited already

        ++ans;
        grid[row][col] = -1; //mark visited

        dfs(grid, row-1, col, ans);
        dfs(grid, row+1, col, ans);
        dfs(grid, row, col-1, ans);
        dfs(grid, row, col+1, ans);
    }
};
