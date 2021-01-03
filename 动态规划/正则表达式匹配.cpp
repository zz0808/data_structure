// 双序列型动态规划，从两个序列的末尾开始匹配，并递归到子问题

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool f[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    f[i][j] = true;
                    continue;
                }
                if (j == 0) { // 匹配串为空
                    f[i][j] = false;
                    continue;
                }
                f[i][j] = false;
                if (p[j - 1] != '*') {
                    if (i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) {
                        f[i][j] = f[i - 1][j - 1];
                    }
                } else {
                    if (j > 1) {
                        f[i][j] = f[i][j - 2]; // *匹配0次
                    }
                    if (j > 1 && i > 0) {
                        if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                            f[i][j] |= f[i - 1][j];
                        }
                    }
                }
            }
        }
        return f[m][n];
    }
};