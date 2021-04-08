class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        int m = s.length();
        // 边界情况
        if (m == 0 || s[0] == '0') {
            return 0;
        }
        int f[m + 1];
        f[0] = 1;

        for (int i = 1; i <= m; i++) {
            f[i] = 0;
            if (s[i - 1] - '0' > 0) {
                f[i] += f[i - 1];
            }
            if (i >= 2) {
                int d = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (d >= 10 && d <= 26) {
                    f[i] += f[i - 2];
                }
            }
        }
        return f[m];
    }
};
