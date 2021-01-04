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
                if (j == 0) {
                    f[i][j] = false;
                    continue;
                }
                f[i][j] = false;
                if (p[j - 1] != '*') {
                    if (i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '?')) {
                        f[i][j] = f[i - 1][j - 1];
                    }
                } else {
                    f[i][j] = f[i][j - 1]; // 式1
                    if (i > 0) {
                        f[i][j] |= f[i - 1][j]; // 式1可能为true，所以这里用 或
                    }
                }
            }
        }

        return f[m][n];
    }
};