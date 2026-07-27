class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<nums.size();++i){
            // window size invalid remove the invalid index
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }

            // remove the idx smaller than the current value
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // push the curr idx
            dq.push_back(i);

            // Record maximum (front of deque) once the first window is complete
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;


    }
};
