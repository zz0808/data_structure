class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        if (n == 0) {
            return 0;
        }
    	int f[n + 1][V + 1];
    	f[0][0] = 0;
    	
    	for (int v = 1; v <= V; v++) {
    		f[0][v] = -1;
    	}
     	for (int i = 1; i <= n; i++) {
    		f[i][0] = 0;
    	}       
    	for (int i = 1; i <= n; i++) {
    		for (int v = 1; v <= V; v++) {
    			f[i][v] = f[i - 1][v];
    			if (v >= vw[i - 1][0] && f[i - 1][v - vw[i - 1][0]] != -1) {
    				f[i][v] = max(f[i][v], f[i - 1][v - vw[i - 1][0]] + vw[i - 1][1]);
    			}
    		}
    	}

    	int ans = 0;

    	for (int v = 0; v <= V; v++) {
    		if (f[n][v] != -1) {
    			ans = max(ans, f[n][v]);
    		}
    	}

    	return ans;
    }
};
