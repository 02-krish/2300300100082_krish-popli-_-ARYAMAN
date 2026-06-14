class Solution {
public:
       bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row - 1;
        int ans = -1;

         
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid][0] == target)
                return true;

            if (matrix[mid][0] < target) {
                ans = mid;        
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (ans == -1)   // target smaller than first element
            return false;

        // Step 2: Binary search in that row
        return binarysearch(matrix, target, ans);
    }
 
    bool binarysearch(vector<vector<int>>& matrix, int target, int r) {
        int low = 0;
        int high = matrix[r].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[r][mid] == target)
                return true;
            else if (matrix[r][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

