class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Find row where elememt exists
        int l=0, h=m-1;
        while(l<=h){
            int midRow = l + (h-l)/2;
            if(matrix[midRow][n-1] == target) return true;
            else if(target < matrix[midRow][n-1]) h = midRow -1;
            else l = midRow+1;
        }

        int row = l;
        // edge cases
        if(l>=m) return false;
        if(matrix[l][0] > target) return false;

        // Find col
        l=0, h=n-1;
        while(l<=h){
            int midCol = l+(h-l)/2;
            if(matrix[row][midCol] == target) return true;
            else if(target < matrix[row][midCol]) h = midCol -1;
            else l = midCol+1;
        }

        return false;
    }
};
