class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        int up[m][n], down[m][n], left[m][n], right[m][n];
        // up        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    up[i][j] = 0;
                    continue;
                }
                up[i][j] = grid[i][j] == 'E' ? 1 : 0;
                if (i > 0)
                    up[i][j] += up[i - 1][j];
            }
        }
       // down
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    down[i][j] = 0;
                    continue;
                }
                down[i][j] = grid[i][j] == 'E' ? 1 : 0;
                if (i < m - 1)
                    down[i][j] += down[i + 1][j];
            }
        }

        // left
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    left[i][j] = 0;
                    continue;
                }
                left[i][j] = grid[i][j] == 'E' ? 1 : 0;
                if (j > 0)
                    left[i][j] += left[i][j - 1];
            }
        }
        // right
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    right[i][j] = 0;
                    continue;
                }
                right[i][j] = grid[i][j] == 'E' ? 1 : 0;
                if (j < n - 1)
                    right[i][j] += right[i][j + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    int t = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};
