/*
    和1相比，可以在任意买卖，前提是买入前手头没有股票
    上升趋势就买入
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int ans = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                ans = ans + prices[i] - prices[i - 1];
            }
        }

        return ans;
    }
};