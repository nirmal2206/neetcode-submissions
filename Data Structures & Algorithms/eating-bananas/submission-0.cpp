class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        int maxPile = *max_element(piles.begin(), piles.end());
        
        int l=1, h=maxPile;
        while(l<=h){
            int mid = l+(h-l)/2;
            int curr_h=0;
            for(int pile:piles){
                curr_h += (pile + mid - 1)/mid;
            }
            if(curr_h<=hr) h=mid-1;
            else l=mid+1; 
        }
        return l;
    }
};
