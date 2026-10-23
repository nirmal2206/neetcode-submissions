class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        // diag1 -> \ and diag2 -> /
        vector<int> col(n,0), diag1(2*n-1, 0), diag2(2*n-1, 0);
        backtrack(n, 0, board, col, diag1, diag2, res);
        return res;
    }

    void backtrack(int n, int row, vector<string>& board, vector<int>& col, vector<int>& diag1, vector<int>&diag2, vector<vector<string>>& res){
        if(row==n){
            res.push_back(board);
            return;
        }

        for(int c=0;c<n;c++){
            // diag1 -> \
            // adding n-1 to make sure the d1 value is always positive
            int d1 = row - c + (n-1); 
            int d2 = row + c; // diag2 -> /

            if(col[c] || diag1[d1] || diag2[d2]) continue; // attacked -> skip
            // Place the queen
            board[row][c] = 'Q';
            col[c] = diag1[d1] = diag2[d2] = 1;

            backtrack(n, row+1, board, col, diag1, diag2, res);

            // Remove the queen
            board[row][c] = '.';
            col[c] = diag1[d1] = diag2[d2] = 0;
        }
    }
};
