class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        backtrack(n, 0, 0, path, res);
        return res;
    }

    void backtrack(int n, int open, int close, string& path, vector<string>& res){
        if(path.size() == 2*n){
            res.push_back(path);
            return;
        }

        // we cannot have more the n open parenthesis
        if(open < n){
            path.push_back('(');
            backtrack(n, open+1, close, path, res);
            path.pop_back();
        }

        //handle close parenthesis
        // we cannot have more closed parenthesis than open parenthesis
        if(close < open){
            path.push_back(')');
            backtrack(n, open, close+1, path, res);
            path.pop_back();
        }
    }
};
