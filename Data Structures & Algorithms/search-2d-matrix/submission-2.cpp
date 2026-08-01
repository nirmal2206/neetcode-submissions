class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // --- Pass 1: Find the Row ---
        int top = 0, bottom = m - 1;
        int candidateRow = -1;

        while (top <= bottom) {
            int midRow = top + (bottom - top) / 2;
            if (matrix[midRow][n - 1] == target) {
                return true;
            } else if (matrix[midRow][n - 1] < target) {
                top = midRow + 1;
            } else {
                // Potential row, but check higher rows just in case
                candidateRow = midRow; 
                bottom = midRow - 1;
            }
        }
        
        // If no valid row found (target larger than all last elements)
        if (top >= m) return false;
        int row = top; 

        // Optional safety check: if target is smaller than the first element of this row
        if (matrix[row][0] > target) return false;

        // --- Pass 2: Search the Row ---
        int left = 0, right = n - 1;
        while (left <= right) {
            int midCol = left + (right - left) / 2;
            if (matrix[row][midCol] == target) {
                return true;
            } else if (matrix[row][midCol] < target) {
                left = midCol + 1;
            } else {
                right = midCol - 1;
            }
        }

        return false;
    }
};
