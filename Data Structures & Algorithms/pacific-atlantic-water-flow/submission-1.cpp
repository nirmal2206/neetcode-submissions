class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows,vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols, false));
        queue<pair<int, int>> pacQ, atlQ;

        for(int c=0;c<cols;++c){
            pacQ.push({0,c});
            atlQ.push({rows-1, c});
        }

        for(int r=0;r<rows;++r){
            pacQ.push({r, 0});
            atlQ.push({r, cols-1});
        }

        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);

        vector<vector<int>> res;
        for(int r=0; r<rows;++r){
            for(int c=0; c<cols; ++c){
                if(pacific[r][c] && atlantic[r][c]){
                    res.push_back({r, c});
                }
            }
        }
        return res;

    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            ocean[r][c] = true;

            for(auto [dr, dc]: dirs){
                int nr = r+dr;
                int nc = c+dc;

                // curr idx is out of boundary
                if(nr<0 || nr>=heights.size() || nc<0 || nc>=heights[0].size()) continue;

                // already visited or the next height < curr height (water cannot flow)
                if(ocean[nr][nc] || (heights[nr][nc] < heights[r][c])) continue;

                q.push({nr, nc});
            }
            
        }
    }
};
