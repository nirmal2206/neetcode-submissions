class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, n=nums.size();
        int r = n-1;

        //1. Find pivot
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[r]) l = mid+1;
            else r=mid;
        }
        int pivot=l;

        //2. Find the half where the target lies
        if(nums[pivot] <= target && target<= nums[n-1]){
            l=pivot;
            r=n-1;
        } else {
            l=0;
            r=pivot;
        }

        //3. Perform binary search
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
