class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> 
     * @param target int整型 
     * @return bool布尔型
     */
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // write code here
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        int row = start;
        if (matrix[end][0] <= target)
            row = end;
        start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] < target) {
                start = mid;
            } else {
                end = mid; 
            }         
        }
        if (matrix[row][start] == target || matrix[row][end] == target)
            return true;
        return false;
    }
};