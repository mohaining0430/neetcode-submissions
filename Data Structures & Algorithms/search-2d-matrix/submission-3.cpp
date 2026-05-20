class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int rowCnt = matrix.size(), colCnt = matrix[0].size();
        int left = 0, right = rowCnt;

        // Find the first row that is > target
        int row = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        if (left >= 1 && matrix[left - 1][0] <= target) 
            row = left - 1;
        else
            return false;

        // In the found row, find the first col that is > target
        left = 0;
        right = colCnt;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        if (left >= 1 && matrix[row][left - 1] == target)
            return true;
        else
            return false;
    }
};
