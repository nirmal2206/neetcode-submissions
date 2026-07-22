class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0, r=n-1;
        int ans =0;
        while(l<r){
            int width = r-l;
            int minHeight = min(heights[l], heights[r]);
            ans = max(ans, minHeight * width);
            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
