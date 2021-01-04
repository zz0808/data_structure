// 计算数组的全子集，组合问题，2^n

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S) {
        vector<vector<int>> ans;
        sort(S.begin(), S.end());
        for (int i = 0; i <= S.size(); i++) {
            vector<int> now_set;
            dfs(ans, S, now_set, 0, i);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& ans, const vector<int> &S, vector<int>& now_set, int start_index, int sz) {
        if (now_set.size() == sz) {
            ans.emplace_back(now_set);
            return;
        }
        for (int i = start_index; i < S.size(); i++) {
            now_set.emplace_back(S[i]);
            dfs(ans, S, now_set, i + 1, sz);
            now_set.pop_back();
        }
    }
};