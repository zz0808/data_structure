#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    fill(e[0], e[0] + 510 * 510, INT_MAX);
    fill(dis, dis + 510, INT_MAX);
    bool visit[510] = { false };

    dis[c1] = 0;

    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }

    for (int i = 0; i < m; i++) {
    	int u = -1, maxn = INT_MAX;
    	for (int j = 0; j < m; j++) {
    		if (!visit[j] && dis[j] < maxn) {
    			maxn = dis[j];
    			u = j;
    		}
    	}
    	if (u == -1) break;
    	visit[u] = true;
    	for (int v = 0; v < m; v++) {
    		if (!visit[v] && e[u][v] != INT_MAX) {
    			if (dis[v] > e[u][v] + dis[u]) {
    				dis[v] = dis[u] + e[u][v];
    			}
    		}
    	}
    }

// 堆优化 O(logV * E)

	return 0;
}