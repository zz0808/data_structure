class Solution {
public:
    /**
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& grid) {
        // write code here
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = 0;
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = 0;
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        } 
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
