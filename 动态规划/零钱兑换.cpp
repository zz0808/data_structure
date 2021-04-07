class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int f[amount + 1];
        f[0] = 0;

        for (int i = 1; i <= amount; i++) {
            f[i] = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && f[i - coins[j]] != INT_MAX) {
                    f[i] = min(f[i], f[i - coins[j]] + 1);
                }                
            }
        }

        return f[amount] == INT_MAX ? -1 : f[amount];
    }

};
