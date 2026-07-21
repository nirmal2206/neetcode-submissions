class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int n:nums){
            mp[n]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [key, freq]:mp){
            buckets[freq].push_back(key);
        }
        // print buckets for debugging
        // for (const auto& group : buckets) {
        //     cout << "[";
        //     for (size_t i = 0; i < group.size(); ++i) {
        //         cout << group[i];
        //         if (i != group.size() - 1) cout << ", ";
        //     }
        //     cout << "]" << endl;
        // }
        for(int i=nums.size(); i>0 && ans.size()<k; --i){
            for(int& val: buckets[i]){
                ans.push_back(val);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
