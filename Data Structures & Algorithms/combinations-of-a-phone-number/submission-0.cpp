class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        string path;
        string digitMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtracking(digits, 0, path, digitMap, res);
        return res;
    }

    void backtracking(string& digits, int idx, string& path, const string digitMap[], vector<string>& res){

        if(idx == digits.size()){
            res.push_back(path);
            return;
        }

        for(char ch: digitMap[digits[idx] - '0']){
            path.push_back(ch);
            backtracking(digits, idx+1, path, digitMap, res);
            path.pop_back();
        }
    }
};
