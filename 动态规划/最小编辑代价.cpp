class Solution {
public:

    int minEditCost(string str1, string str2, int ic, int dc, int rc) {

        int m = str1.length(), n = str2.length();
        int f[m + 1][n + 1]; 
        // 初始化
        for (int i = 0; i <= m; i++) {
            f[i][0] = i * dc;
        }
        for (int i = 0; i <= n; i++) {
            f[0][i] = i * ic;
        }
        // 动态规划，从大问题向子问题计算
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = 0;
                // 如果末尾字符相等
                if (str1[i - 1] == str2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                                    // 插入               // 删除              // 修改
                    f[i][j] = min(f[i][j - 1] + ic, min(f[i - 1][j] + dc, f[i - 1][j - 1] + rc));
                }
            }
        }
        return f[m][n];
    }
};