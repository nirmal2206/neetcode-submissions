class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res = {""};
        string digitMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for(char digit:digits){
            vector<string> tmp;
            for(string& currStr: res){
                for(char ch: digitMap[digit - '0']){
                    tmp.push_back(currStr+ch);
                }
            }
            res = tmp;
        }

        return res;
    }
};
