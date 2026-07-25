class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.size();
        int ans=0;
        unordered_set<char> seen;

        for(int r=0;r<n;++r){
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
