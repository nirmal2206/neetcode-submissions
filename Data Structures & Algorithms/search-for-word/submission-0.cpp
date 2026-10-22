class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row=0;row<board.size();++row){
            for(int col=0; col<board[0].size();++col){
                if(backtrack(board, word, 0, row, col)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int idx, int row, int col){
        
        if(idx==word.size()) return true;

        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;

        if(board[row][col] != word[idx]) return false;

        char tmp = board[row][col];
        board[row][col] = '#'; //mark the word as visited

        bool found = backtrack(board, word, idx+1, row-1, col) ||
                        backtrack(board, word, idx+1, row+1, col) ||
                        backtrack(board, word, idx+1, row, col-1) ||
                        backtrack(board, word, idx+1, row, col+1);

        board[row][col] = tmp; // unmark visited or revert back to prev value

        return found;
    }
};
