class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        int i = 0, j = 0;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        
        int k = m * n;
        while (k > 0) {
            for (int now = left; now <= right && k > 0; now++) {
                ans.push_back(matrix[top][now]);
                k--;
            }
            top++;
            for (int now = top; now <= bottom && k > 0; now++) {
                ans.push_back(matrix[now][right]);
                k--;
            }           
            right--;
            for (int now = right; now >= left && k > 0; now--) {
                ans.push_back(matrix[bottom][now]);
                k--;
            }              
            bottom--;
            for (int now = bottom; now >= top && k > 0; now--) {
                ans.push_back(matrix[now][left]);
                k--;
            }              
            left++;
        }
        
        return ans;
    }
};
