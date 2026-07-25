class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        vector<int> freq(26, 0);
        int maxCount=0, ans=0;
        
        for(int r=0;r<s.size();++r){
            // Include current character in window
            int idx = s[r] - 'A';
            freq[idx]++;
            
            // Set/update global max
            maxCount = max(maxCount, freq[idx]);

            // If invalid, shrink window from left
            // Condition: (Window Length) - (Max Freq) > k
            if((r-l+1) - maxCount > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
