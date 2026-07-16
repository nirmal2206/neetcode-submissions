class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> nums(26, 0);
        if(s.length() != t.length()) return false;
        
        for(int i=0;i<s.size();++i){
            nums[s[i]-'a']++;
            nums[t[i]-'a']--;
        }
        for(int n:nums){
            if(n!=0) return false;
        }
        return true;
    }
};
