class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int solve(vector<vector<char> >& grid) {
        // write code here
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    void bfs (vector<vector<char>>& grid, int i, int j) {
        
        queue<pair<int, int>> q;
        q.emplace(i, j);
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
//             grid[p.first][p.second] = '0';
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + p.first, y = dy[k] + p.second;
                if (is_inbound(grid.size(), grid[0].size(), x, y) && grid[x][y] == '1') {
                    q.emplace(x, y);
                    grid[x][y] = '0';
                }
            }
        }
    }
    bool is_inbound(int m, int n, int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        return false;
    }
};
