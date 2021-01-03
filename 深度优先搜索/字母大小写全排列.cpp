// 给一个字符串，把字符大小写转换，得到新的字符串，计算所有这种组合

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        if (S.length() == 0) {
            return ans;
        }
        string cur_set = S;
        dfs(ans, cur_set, 0);

        return ans;
    }

    void dfs(vector<string>& ans, string& cur_set, int start_index) {

        if (start_index == cur_set.length()) {
            ans.push_back(cur_set);
            return;
        }
        cur_set += char2str(cur_set[start_index]);
        dfs(ans, cur_set, start_index + 1);
        if (isalpha(cur_set[start_index])) {
            cur_set[start_index] ^= 1 << 5;
            dfs(ans, cur_set, start_index + 1);
        }

    }
    string char2str(char c) {
        stringstream stream;
        stream >> c;
        return stream.str();
    }
};


