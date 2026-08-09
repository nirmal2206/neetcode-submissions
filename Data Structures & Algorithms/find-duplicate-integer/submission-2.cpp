class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();++i){
            int idx = abs(nums[i]);

            // If already negative, we found the duplicate
            if(nums[idx] < 0) return idx;

            // Mark as visited by making it negative
            nums[idx] = -nums[idx];
        }

        return -1; // will not reach here
    }
};
