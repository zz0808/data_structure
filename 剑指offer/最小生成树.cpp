class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最小的花费代价使得这n户人家连接起来
     * @param n int n户人家的村庄
     * @param m int m条路
     * @param cost intvector<vector<>> 一维3个参数，表示连接1个村庄到另外1个村庄的花费的代价
     * @return int
     */
    int find(int x) { // 并查集合并
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
    
    int miniSpanningTree(int n, int m, vector<vector<int> >& cost) {
        // write code here
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        sort(cost.begin(), cost.begin() + m, [](vector<int>& lhs, vector<int>& rhs){
            return lhs[2] < rhs[2]; 
        });
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (find(cost[i][0]) != find(cost[i][1])) {
                ans += cost[i][2]; // 加路
                p[find(cost[i][0])] = find(cost[i][1]);
            }
        }
        return ans;
            
    }
private:
    int p[100010];
};
