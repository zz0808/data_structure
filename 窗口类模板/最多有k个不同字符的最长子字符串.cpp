class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int char_set[256] = { 0 };
        int m = s.length();
        int ans = 0, start = 0, cnt = 0;
        for (int i = 0; i < m; i++) {
            if (char_set[s[i]]++ == 0) {
                cnt++;
            }
            while (cnt > k) {
                char_set[s[start]]--;
                if (char_set[s[start]] == 0) {
                    cnt--;
                }
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
