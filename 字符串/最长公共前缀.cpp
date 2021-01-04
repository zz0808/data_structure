// 给一组字符串，找到它们的最长公共子前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];

        sort(strs.begin(), strs.end()); // 排序
        string a = strs[0], b = strs[strs.size() - 1];
        int i;
        for (i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                break;
            }
        }
        return a.substr(0, i);
    }
};