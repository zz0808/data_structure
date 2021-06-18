class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    string solve(vector<int>& nums) {
        // write code here
        if (nums.size() == 0) {
            return "0";
        }
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }
        vector<string> strs;
        for (auto& num : nums) {
            strs.push_back(to_string(num));
        }
        auto cmp = [](const string& lhs, const string& rhs) {
            if (lhs + rhs > rhs + lhs) {
                return true;
            } else {
                return false;
            }
        };
        
        sort(strs.begin(), strs.end(), cmp);
        if (strs[0] == "0") { // 注意输入全为0的情况
            return "0";
        }
        string ans = "";
        for (auto& str : strs) {
            ans += str;
        }
        return ans;
    }
};
