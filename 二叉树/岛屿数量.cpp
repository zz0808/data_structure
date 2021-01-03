class Solution {
public:
	bool in_bound(int m, int n, int i, int j) {
		if (i >= 0 && i < m && j >= 0 && j < n) {

		}
	}
    int numIslands(vector<vector<char>>& grid) {
    	int m = grid.size(), n = grid[0].size(), ans = 0;

    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (grid[i][j] == '1') {

    			}
    		}
    	}

    	return ans;
    }

    void bfs(vector<vector<char>>& grid, int m, int n, int i, int j) {

    	pair<int, int> p = {i, j};
    	queue<pair<int,int>> q;
    	q.emplace(p);

    	while(!q.empty()) {
    		pair<int, int> now = q.front();
    		q.pop();
    		for (int k = 0; k < 4; k++) {
    			if ()
    		}
    	}
    }
};


int flowers(vector<int>& scores) {

        if (scores.size() == 0)
            return 0;
        int up = 0, down = 0, ans = 1, peek = 1;
        
        for (int i = 1; i < scores.size(); i++) {
            ans++;
            if (scores[i] > scores[i - 1]) {
                down = 0;
                up++;
                ans += up;
                peek = up + 1;
            } else if (scores[i] == scores[i - 1]) {
                down = 0, up = 0, peek = 1;
            } else {
                up = 0;
                ans += down;
                down++;
                if (peek <= down) 
                    ans++;
            }
        }
        
        return ans;
}

int flowers(vector<int>& scores) { 

    if (scores.size() == 0)
        return 0;

    int up = 0, down = 0, peek = 1, ans = 1;

    for (int i = 1; i < scores.size(); i++) {
    	ans++;
    	if (scores[i] > scores[i - 1]) {
    		up++;
    		down = 0;
    		ans += up;
    		peek = up + 1;
    	} else if(scores[i] == scores[i - 1]) {
    		up = 0, down = 0, peek = 1;
    	} else {
    		up = 0;
    		ans += down;
    		down++;
    		if (down >= peek) {
    			ans++;
    		}
    	}
    }


}






