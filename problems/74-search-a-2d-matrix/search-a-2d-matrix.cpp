class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n - 1;
        
        // Binary search over the "flattened" matrix.
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // Map 1D index 'mid' to 2D indices 'r' and 'c'
            int r = mid / n, c = mid % n;
            
            // Check if we found the target.
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return false;
    }
};
