
// 和3相似，只不过2变成了k， 注意当k > n/2时，等价于任意次买卖，即问题2，可用滚动数组优化
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        if (k > n / 2) {
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    ans = ans + prices[i] - prices[i - 1];
                }
            }
            return ans;
        }
        int f[n + 1][2 * k + 2];
        f[0][1] = 0;
        for (int i = 2; i <= 2 * k + 1; i++) {
            f[0][i] = INT_MIN;
        }
        for (int i = 1; i <= n; i++) {
            // 未持有股票
            // f[i][j] = max(f[i-1][j], f[i-1][j-1]+p[i-1]-p[i-2])
            for (int j = 1; j <= 2 * k + 1; j += 2) {
                f[i][j] = f[i - 1][j];
                if (i >= 2 && j >= 2 && f[i - 1][j - 1] != INT_MIN) {
                    int obtain = prices[i - 1] - prices[i - 2];
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + obtain);
                }
            }
            // 持有股票
            // f[i][j] = max(f[i-1][j]+p[i-1][i-2], f[i-1][j-1])
            for (int j = 2; j <= 2 * k; j += 2) {
                f[i][j] = f[i - 1][j - 1];
                if (i >= 2 && f[i - 1][j] != INT_MIN) {
                    int obtain = prices[i - 1] - prices[i - 2];
                    f[i][j] = max(f[i][j], f[i - 1][j] + obtain);
                }
            }
        }
  
        for (int i = 1; i <= 2 * k + 1; i += 2) {
            ans = max(ans, f[n][i]);
        }

        return ans;
    }
};