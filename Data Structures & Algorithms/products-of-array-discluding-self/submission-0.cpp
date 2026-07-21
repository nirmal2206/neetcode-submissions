class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n);
        leftProd[0]=1;
        for(int i=1;i<n;++i){
            leftProd[i] = leftProd[i-1] * nums[i-1];
        }
        int rightProd = nums[n-1];
        for(int i=n-2;i>=0;--i){
            leftProd[i] = rightProd * leftProd[i];
            rightProd *= nums[i];
        }
        return leftProd;
    }
};
