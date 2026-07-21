class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string s: strs){
            vector<int> arr(26,0);
            for(char ch:s){
                arr[ch-'a']++;
            }
            string key="";
            for(int i=0;i<26;++i){
                key+=to_string(arr[i])+"#";
            }
            mp[key].push_back(s);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
