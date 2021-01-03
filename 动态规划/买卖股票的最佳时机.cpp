// 枚举在哪一天卖，同时保存当前的最小值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int minp = prices[0];
        int ans = 0;

        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - minp);
            minp = min(minp, prices[i]);
        }

        return ans;
    }
};