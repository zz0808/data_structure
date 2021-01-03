// 给一个字符串，返回所有的排列组合，要求结果按字典序，并且不能包含重复的结果

#include <unordered_set>
class Solution {
public:
    vector<string> Permutation(string str) {
        
        if (str.length() == 0)
            return {};
        unordered_set<string> uset; // 因为要去重，先用set存储
        vector<bool> used(str.length(), false); // 这里不能使用set存储已用过的字符，因为字符串可能有重复的字符
        string cur_str = "";
        dfs(uset, str, cur_str, used);
        vector<string> ans(uset.begin(), uset.end());
        sort(ans.begin(), ans.end()); // 排序
        return ans;
    }
    void dfs(unordered_set<string>& ans, string& str, string& cur_str, vector<bool>& used) {
        if (cur_str.length() == str.length()) {
            ans.insert(cur_str);
            return;
        }
        for (int i = 0; i < str.length(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            cur_str.push_back(str[i]);
            dfs(ans, str, cur_str, used);
            used[i] = false;
            cur_str.pop_back();
        }
    }

};