class Solution {
public:

    string solve(string s, string t) {
        
        if(s.empty() == true || t.size() == true)
            return "0";
        
        int lens = s.length(), lent = t.length();
        string ans(lens + lent, '0'); // 最多就是 lens + lent
        
        for (int i = lens - 1; i >= 0; i--) {
            for (int j = lent - 1; j >= 0; j--) {
                int temp = (s[i] - '0') * (t[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = temp % 10 + '0';
                ans[i + j] = ans[i + j] + temp / 10;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return ans;
    }
};