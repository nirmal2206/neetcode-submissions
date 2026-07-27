class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length() < t.length()) return "";
        vector<int> charFreq(128,0);
        
        for(char ch:t){
            charFreq[ch]++;
        }

        int required=t.length();
        int l=0, minLen=INT_MAX, minL = 0;
        
        for(int r=0;r<s.size();++r){
            if(charFreq[s[r]] > 0) required--;

            charFreq[s[r]]--;

            while(required == 0){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    minL = l;
                }
                charFreq[s[l]]++;
                if(charFreq[s[l]] > 0) required++;
                l++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(minL, minLen);

    }
};
