class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res){
        res.push_back(path);

        for(int i=start; i<nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1]) continue; //skip duplicates that are already calculated at this level
            path.push_back(nums[i]);
            backtrack(nums, i+1, path, res);
            path.pop_back();
        }
    }
};
