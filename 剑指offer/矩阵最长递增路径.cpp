class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int dirs[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> max_path;
    int solve(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size();
        int n = matrix[0].size();
        
        max_path.resize(m,vector<int>(n, 0));
        
        int ans = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j, m, n));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int> >& matrix, int x, int y, int m, int n) {
        if (max_path[x][y] > 0) {
            return max_path[x][y];
        }
        max_path[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dirs[k];
            int ny = y + dirs[k + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] < matrix[x][y]) {
                max_path[x][y] = max(max_path[x][y], 1 + dfs(matrix, nx, ny, m, n));
            }
        }
        return max_path[x][y];
    }
};
