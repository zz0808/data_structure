class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int m = costs.size();

        if ( m == 0) {
            return 0;
        }
        int f[m][3];  

        f[0][0] = costs[0][0], f[0][1] = costs[0][1], f[0][2] = costs[0][2];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                f[i][j] = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    if (j != k) {
                        f[i][j] = min(f[i - 1][k] + costs[i][j], f[i][j]);
                    }
                }
            }
        }

        return min(f[m - 1][0], min(f[m - 1][1], f[m - 1][2]));
    }
};
