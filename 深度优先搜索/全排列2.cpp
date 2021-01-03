// 必会
class Solution {
public:
    // 和全排列不同点是给的数组可能是重复的
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end());

        vector<int> cur_set;
        vector<bool> chosen(nums.size(), false);

        helper(nums, ans, cur_set, chosen);

        return ans;
    }

    void helper(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_set, vector<bool>& chosen) {

        if (cur_set.size() == nums.size()) {
            ans.emplace_back(cur_set);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (chosen[i] == true) {
                continue;
            }
            // 因为已经排好序，对于重复的数字，选择第一个作为代表，如果第一个没有选择，就不选接下来的重复数
            if (i > 0 && nums[i] == nums[i - 1] && chosen[i - 1] == false) {
                continue;
            }
            chosen[i] = true;
            cur_set.emplace_back(nums[i]);
            helper(nums, ans, cur_set, chosen);
            cur_set.pop_back();
            chosen[i] = false;
        }
    }
};