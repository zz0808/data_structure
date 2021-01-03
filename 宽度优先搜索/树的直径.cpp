/**
 * struct Interval {
 *	int start;
 *	int end;
 * };
 */
// 先从任一点出发，计算出距离该点最长的点p,再从p出发，得到距离p最长的点q，即为所求
class Solution {
public:
    /**
     * 树的直径
     * @param n int整型 树的节点个数
     * @param Tree_edge Interval类vector 树的边
     * @param Edge_value int整型vector 边的权值
     * @return int整型
     */
    pair<int, int> bfs(vector<vector<pair<int, int>>>& edges, int start_point) {
        int n = edges.size();
        int max_len = 0, far_point = start_point;
        queue<int> q;
        vector<int> distance(n, -1);
        distance[start_point] = 0;
        
        q.push(start_point);
        
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto edge : edges[now]) {
                if (distance[edge.first] == -1) {
                    distance[edge.first] = distance[now] + edge.second;
                    q.push(edge.first);
                    if (distance[edge.first] > max_len) {
                        max_len = distance[edge.first];
                        far_point = edge.first;
                    }  
                } 
            }
        }
        return {far_point, max_len};
    }
    int solve(int n, vector<Interval>& Tree_edge, vector<int>& Edge_value) {
        if (n <= 1)
            return 0;
        vector<vector<pair<int, int>>> edges(n);
        for (int i = 0; i < Tree_edge.size(); i++) {
            edges[Tree_edge[i].start].push_back({Tree_edge[i].end, Edge_value[i]});
            edges[Tree_edge[i].end].push_back({Tree_edge[i].start, Edge_value[i]});
        }
        pair<int, int> temp = bfs(edges, 0);
        int now_point = temp.first;
        temp = bfs(edges, now_point);
        
        return temp.second;
        
    }
};