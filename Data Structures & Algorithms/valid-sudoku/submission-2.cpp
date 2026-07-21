class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int r=0;r<9;++r){
            for(int c=0;c<9;++c){
                char num = board[r][c];
                if(num == '.') continue;

                // Calculate which 3x3 box this cell belongs to (0-8)
                int boxIndex = (r/3)*3+(c/3);

                //using contains c++20
                if(rows[r].contains(num) || cols[c].contains(num) || boxes[boxIndex].contains(num)){
                    return false;
                }

                rows[r].insert(num);
                cols[c].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};
