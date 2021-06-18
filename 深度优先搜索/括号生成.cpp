class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n <= 0) {
            return ans;
        }
        string curt;
        dfs(ans, curt, 0, 0, n);
        
        return ans;
    }
    
    void dfs(vector<string>& ans, string& curt, int open, int close, int n) {
        if (curt.length() == 2 * n) {
            ans.push_back(curt);
            return;
        }
        if (open < n) {
            curt.push_back('(');
            dfs(ans, curt, open + 1, close, n);
            curt.pop_back();
        }
        if (close < open) {
            curt.push_back(')');
            dfs(ans, curt, open, close + 1, n);
            curt.pop_back();
        }
    }
};
