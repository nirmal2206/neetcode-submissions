class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        for(int i=0;i<col;++i){
            dfs(0, i, pacific, heights);
            dfs(row-1, i, atlantic, heights);
        }

        for(int i=0;i<row;++i){
            dfs(i, 0, pacific, heights);
            dfs(i, col-1, atlantic, heights);
        }

        vector<vector<int>> res;
        for(int r=0; r<row;++r){
            for(int c=0; c<col; ++c){
                if(pacific[r][c] && atlantic[r][c]){
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

    void dfs(int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        ocean[row][col] = true;

        for(auto [r, c]: dirs){
            int nr = row + r;
            int nc = col + c;

            if(nr<0 || nr>=heights.size() || nc<0 || nc>=heights[0].size()) continue;

            if(ocean[nr][nc] || (heights[nr][nc] < heights[row][col])) continue;

            dfs(nr, nc, ocean, heights);
        }

    }
};