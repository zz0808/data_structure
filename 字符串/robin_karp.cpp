class Solution {
public:
    int kmp(string S, string T) {
        int m = S.length(), n = T.length();
        if (m > n) {
            return 0;
        }
        int ans = 0;
        int pow = 1;
        int targetCode = 0;
        for (int i = 0; i < m; i++) {
            pow = pow * MagicNum % base;
            targetCode = (S[i] + targetCode * MagicNum) % base;
        }
        int sourceCode = 0;
        for (int i = 0; i < n; i++) {
            sourceCode = (T[i] + sourceCode * MagicNum) % base;
            if (i < m - 1) {
                continue;
            }
            if (i >= m) {
                sourceCode = sourceCode - (T[i - m] * pow) % base;
                if (sourceCode < 0) {
                    sourceCode += base;
                }
            }
            if (sourceCode == targetCode) {
                bool flag = true;
                for (int j = 0; j < m; j++) {
                    if (S[j] != T[i - m + 1 + j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) {
                    ans++;                    
                }
            }
        }
        return ans;
    }
    
private:
    const int MagicNum = 31;
    const int base = 100000;
};
