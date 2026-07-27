class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        
        vector<int> s1Freq(26,0);
        vector<int> s2Freq(26,0);

        for(int i=0;i<n1;++i){
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        
        if(s1Freq == s2Freq) return true;

        for(int i=n1;i<n2;++i){
            s2Freq[s2[i] - 'a']++;
            s2Freq[s2[i-n1] - 'a']--;
            if(s1Freq == s2Freq) return true;
        }
        return false;
    }
};
