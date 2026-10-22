class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combinationPath;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, combinationPath, res);
        return res;
    }

    void backtrack(vector<int>& candidates,int start, int remaining, vector<int>& combinationPath, vector<vector<int>>& res){
        
        if(remaining==0){
            res.push_back(combinationPath);
            return;
        }

        for(int i=start;i<candidates.size();++i){
            //exit since the array is sorted the next candidates will definitely cause sum > target
            if(candidates[i] > remaining) break; 

            if(i > start && candidates[i] == candidates[i-1]) continue;
            combinationPath.push_back(candidates[i]);
            backtrack(candidates, i+1, remaining - candidates[i], combinationPath, res);
            combinationPath.pop_back();
        }
    }
};
