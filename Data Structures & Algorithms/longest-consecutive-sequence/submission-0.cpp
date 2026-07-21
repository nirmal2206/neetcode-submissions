class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_set<int> us(nums.begin(), nums.end());
        int longestSeq = 0;
        for(int num: us){
            
            // Check if num-1 exist
            // Exist: skip the num as this cannot be the start of seq
            // not exist: proceed ahead to check num+1 exist and increment curr count
            if(us.find(num-1) == us.end()){
                int currNum = num;
                int currLongSeq = 1;

                while(us.find(currNum+1) != us.end()){
                    currNum++;
                    currLongSeq++;
                }

                longestSeq = max(longestSeq, currLongSeq);
            }
        }
        return longestSeq;
    }
};
