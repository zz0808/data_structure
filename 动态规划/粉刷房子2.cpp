class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &colors) {
        // write your code here
        int m = colors.size();
        if (m == 0) {
            return 0;
        }
        int k = colors[0].size();
        if (k == 0) {
            return 0;
        }

        int min1 = INT_MAX, min2 = INT_MAX, color_id1 = 0, color_id2 = 0;

        for (int i = 0; i < k; k++) {
            if (colors[0][i] < min1) {
                min2 = min1;
                min1 = colors[0][i];
                color_id2 = color_id1;
                color_id1 = i;
            } else if (colors[0][i] < min2) {
                min2 = colors[0][i];
                color_id2 = i;
            }
        }

        for (int i = 1; i < m; i++) {
            int tmin1 = INT_MAX, tmin2 = INT_MAX, tcolor_id1 = 0, tcolor_id2 = 0;
            for (int j = 0; j < k; j++) {
                int temp = (j == color_id1) ? min2 : min1;
                if (temp < tmin1) {
                    tmin2 = tmin1;
                    tcolor_id2 = tcolor_id1;
                    tmin1 = temp;
                    tcolor_id1 = j;
                } else if (temp < tmin2) {
                    tmin2 = temp;
                    tcolor_id2 = j;
                }
            }

            min1 = tmin1, min2 = tmin2;
            color_id1 = tcolor_id1, color_id2 = tcolor_id2;
        }

        return min1;
    }
};
