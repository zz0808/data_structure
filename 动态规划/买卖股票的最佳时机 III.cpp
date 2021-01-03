// 在n天最多允许买卖两次，计算最大收益

|----|------|----|--|-------| 
 未持有  持有   未   持   未

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n + 1][5 + 1];
        f[0][1] = 0;
        for (int i = 2; i <= 5; i++) {
            f[0][i] = INT_MIN;
        }
        // 未持有 1,3,5: f[i][j] = max(f[i-1][j], f[i-1][j-1] + p[i-1]-p[i-2])
        // 持有   2,4  : f[i][j] - max(f[i-1][j] + p[i-1] -p[i-2], f[i-1][j-1])
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j+=2) {
                f[i][j] = f[i - 1][j];
                if (j >= 2 && i >= 2 && f[i - 1][j - 1] != INT_MIN) {
                    int obtain = prices[i - 1] - prices[i - 2];
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + obtain);
                } 
            }
            for (int j = 2; j <= 5; j+=2) {
                f[i][j] = f[i - 1][j - 1];
                if (i >= 2 && f[i - 1][j] != INT_MIN) {
                    int obtain = prices[i - 1] - prices[i - 2];
                    f[i][j] = max(f[i][j], f[i - 1][j] + obtain);
                }
            }
        }

        return max(f[n][1], max(f[n][3], f[n][5])); // 最后只能是空仓的
    }
};