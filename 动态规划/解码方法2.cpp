class Solution {
public:
    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        int m = s.length();
        if (m == 0) {
            return 0;
        }
        int f[m + 1];
        f[0] = 1;

        for (int i = 1; i <= m; i++) {
            f[i] = 0;
            if (s[i - 1] == '*') {
                f[i] = (f[i] + 9L * f[i - 1]) % mod;
                if (i >= 2) {
                    if (s[i - 2] == '*') {
                        f[i] = (f[i] + 15L * f[i - 2]) % mod;
                    } else if (s[i - 2] == '1') {
                        f[i] = (f[i] + 9L * f[i - 2]) % mod;
                    } else if (s[i - 2] == '2') {
                        f[i] = (f[i] + 6L * f[i - 2]) % mod;
                    }
                }
            } else {
                if (s[i - 1] != '0') {
                    f[i] = (f[i] + f[i - 1]) % mod;
                }
                if (i >= 2) {
                    if (s[i - 2] == '*') {
                        if (s[i - 1] <= '6') {
                            f[i] = (f[i] + 2L * f[i - 2]) % mod;
                        }  else {
                            f[i] = (f[i] + f[i - 2]) % mod;
                        }
                    } else {
                        int two_digits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                        if (two_digits >= 10 && two_digits <= 26) {
                            f[i] = (f[i] + f[i - 2]) % mod;
                        }
                    }
                }
            }
        }
        return f[m];
    }
private:
    const int mod = 1000000007;
};
