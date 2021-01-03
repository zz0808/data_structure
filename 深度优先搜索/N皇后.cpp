 class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n <= 0)
            return ans;
        vector<int> cur_set; 
        helper(ans, cur_set, n);
        return ans;
    }

    void helper(vector<vector<string>>& ans, vector<int>& cols, int n) {
        if (cols.size() == n) {
            ans.emplace_back(draw_chess_board(cols));
            return;
        }

        for (int column = 0; column < n; column++) {
            if (!is_valid(cols, column)) {
                continue;
            }
            cols.emplace_back(column);
            helper(ans, cols, n);
            cols.pop_back();
        }
    }
    bool is_valid(const vector<int>& cols, int column) {
        int row = cols.size();
        for (int row_index = 0; row_index < cols.size(); row_index++) {
            if (cols[row_index] == column)
                return false;
            if (cols[row_index] + row_index == row + column)
                return false;
            if (cols[row_index] - row_index == column - row)
                return false;
        }
        return true;
    }
    vector<string> draw_chess_board(const vector<int>& cols) {
        vector<string> ans;
        for (int i = 0; i < cols.size(); i++) {
            string now = "";
            for (int j = 0; j < cols.size(); j++) {
                now = now + (cols[i] == j ? "Q" : ".");
            }
            ans.emplace_back(now);
        }
        return ans;

    }
};