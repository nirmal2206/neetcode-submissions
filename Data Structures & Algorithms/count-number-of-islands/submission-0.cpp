class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int row=0;row<grid.size();++row){
            for(int col=0;col<grid[0].size();++col){
                if(grid[row][col] == '1'){
                    ++count;
                    dfs(grid, row, col);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col){

        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return;

        if(grid[row][col] != '1') return; // not valid or is water

        grid[row][col] = '#'; // Mark as visited

        dfs(grid, row-1, col);
        dfs(grid, row+1, col);
        dfs(grid, row, col-1);
        dfs(grid, row, col+1);

    }
};
