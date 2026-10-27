class Solution {
    int dirs[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r=0;r<rows;++r){
            if(board[r][0] == 'O') dfs(r, 0, board);
            if(board[r][cols-1] == 'O') dfs(r, cols-1, board);
        }
        for(int c=0;c<cols;++c){
            if(board[0][c] == 'O') dfs(0, c, board);
            if(board[rows-1][c] == 'O') dfs(rows-1, c, board);
        }

        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(board[r][c] == 'O') board[r][c] = 'X';
                else if(board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }

    void dfs(int row, int col, vector<vector<char>>& board){

        board[row][col] = 'T';

        for(auto[dr, dc]: dirs){
            int nr = row+dr;
            int nc = col+dc;
            if(nr<0 || nr>=board.size() || nc<0 || nc>=board[0].size()) continue;
            if(board[nr][nc]!='O') continue;
            dfs(nr, nc, board);
        }
    }
};
