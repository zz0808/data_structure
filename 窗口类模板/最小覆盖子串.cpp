class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int source_hash[256] = { 0 };
        int target_hash[256] = { 0 };
        for (int i = 0; i < t.length(); i++) {
            target_hash[t[i]]++;
        }
        int i, j = 0;
        int min_len = INT_MAX;
        for (i = 0; i < s.length(); i++) {
            while (j < s.length() && !valid(source_hash, target_hash)) {
                source_hash[s[j]]++;
                j++;
            }
            if (valid(source_hash, target_hash)) {
                if (j - i < min_len) {
                    min_len = j - i;
                    ans = s.substr(i, j - i);
                }
            }
            source_hash[s[i]]--;
        }
        return ans;
    }

    bool valid(int* source_hash, int* target_hash) {
        for (int i = 0; i < 256; i++) {
            if (target_hash[i] > source_hash[i]) {
                return false;
            }
        }
        return true;
    }
};
