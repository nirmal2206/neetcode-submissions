class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n);
        leftProd[0]=1;
        // left side prod
        for(int i=1;i<n;++i){
            leftProd[i] = leftProd[i-1] * nums[i-1];
        }
        //right side prod * left side 
        int rightProd = 1;
        for(int i=n-1;i>=0;--i){
            leftProd[i] = rightProd * leftProd[i];
            rightProd *= nums[i];
        }
        return leftProd;
    }
};
