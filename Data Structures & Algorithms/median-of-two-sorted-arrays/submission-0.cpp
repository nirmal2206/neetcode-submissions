class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m=nums1.size(), n=nums2.size();
        int l=0, r=m;
        while(l<=r){
            int part1 = l + (r-l)/2;
            int part2 = (m+n+1)/2 - part1;

            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int minRight1 = (part1 == m) ? INT_MAX : nums1[part1];

            int maxLeft2 = part2==0 ? INT_MIN : nums2[part2 - 1];
            int minRight2 = (part2 == n) ? INT_MAX : nums2[part2];

            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1){
                // Found correct partiton
                if((m+n)%2 == 1){
                    return max(maxLeft1, maxLeft2);
                } else {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2))/2.0;
                }
            } else if (maxLeft1 > minRight2) {
                // part1 is too far to the right or
                // need to divide left part further 
                r = part1 - 1;
            }
            else {
                // part1 is too far to the left or
                // need to divide right part further 
                l = part1+1;
            }
        }

        return 0.0; //Will never reach here
    }
};
