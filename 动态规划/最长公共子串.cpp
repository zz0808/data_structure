class Solution {
public:
    string LCS(string str1, string str2) {
        // write code here
        int m = str1.length(), n = str2.length();
        int dp[n];
        int end_index = -1, max_len = 0;
        fill(dp, dp + n, 0);
        
        for (int i = 0; i < m; i++) {
            int last = 0;
            for (int j = 0; j < n; j++) {
                int temp = dp[j];
                if (str1[i] == str2[j]) {
                    dp[j] = last + 1;
                } else {
                    dp[j] = 0;
                }
                if (dp[j] > max_len) {
                    max_len = dp[j];
                    end_index = j;
                } 
                last = temp;
            }
        }
        return end_index == -1 ? "-1" : str2.substr(end_index - max_len + 1, max_len);
    }
};
