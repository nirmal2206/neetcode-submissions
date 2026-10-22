class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        backtrack(nums, 0, target, res, combination);
        return res;
    }

    void backtrack(vector<int>& nums, int start, int remaining, vector<vector<int>>& res,  vector<int>& combination){

        if(remaining == 0){
            res.push_back(combination);
            return;
        }

        for(int i=start; i<nums.size();++i){
            if(nums[i]>remaining) continue; // skip this number - adding will give a sum > target
            combination.push_back(nums[i]);

            backtrack(nums, i, remaining-nums[i], res, combination);

            combination.pop_back();
        }
    }
};
