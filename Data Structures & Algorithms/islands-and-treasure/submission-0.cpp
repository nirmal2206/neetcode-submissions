class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int INF = INT_MAX;

        queue<pair<int, int>> q;

        // push all 0 - treasure chest
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){

            auto [r, c] = q.front();
            q.pop();

            for(auto& d:dir){
                int nr = r+d[0];
                int nc = c+d[1];

                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;

                if(grid[nr][nc] != INF) continue; // water or already visited

                grid[nr][nc] = grid[r][c]+1;

                q.push({nr, nc});
            }
        }
    }
};
