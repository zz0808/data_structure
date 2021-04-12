class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool map[256] = { false };
        int ans = 0;
        int i, j = 0;

        for (i = 0; i < s.length(); i++) {
            while (j < s.length() && !map[s[j]]) {
                map[s[j]] = true;
                ans = max(ans, j + 1 - i);
                j++;
            }
            map[s[i]] = false;
        }

        return ans;
    }
};
