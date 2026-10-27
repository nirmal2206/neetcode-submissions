class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[4][2] = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        int fresh = 0, time = 0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) ++fresh;
            }
        }

        while(!q.empty() && fresh > 0){
            ++time;
            int qSize = q.size();
            for(int i=0;i<qSize;++i){
                auto [r, c] = q.front();
                q.pop();
                for(auto& dir: dirs){
                    int nr = r+dir[0];
                    int nc = c+dir[1];

                    if(nr<0 || nr>=m || nc<0 || nc>=n) continue;

                    if(grid[nr][nc] != 1) continue; // cell empty or rotten already

                    grid[nr][nc] = 2;
                    --fresh;

                    q.push({nr, nc});
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
