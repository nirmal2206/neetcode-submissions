class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n=matrix[0].size();

        int l=0, h = (m*n)-1;

        while(l<=h){
            int mid = l + (h-l)/2;

            int r = mid/n; // Row index
            int c = mid%n; // Col index

            if(matrix[r][c] == target) return true;
            else if(target < matrix[r][c]) h = mid-1;
            else l = mid+1;
        }

        return false;
    }
};
