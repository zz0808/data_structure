// 排列
// 时间复杂度 O(n!)
// 必会
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;

        unordered_set<int> permutation; // 记录当前已经出现的数字
        vector<int> cur_set;

        helper(nums, permutation, cur_set, ans);

        return ans;
    }
    // 和组合问题相比，不需要记录start_index，因为每个答案都是无序的
    void helper(const vector<int>& nums, unordered_set<int>& permutation, vector<int>& cur_set, vector<vector<int>>& ans) {

    	// 递归出口，当全部数字都出现时
        if (cur_set.size() == nums.size()) {
            ans.emplace_back(cur_set);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (permutation.find(nums[i]) != permutation.end()) { // 如果当前数字已经出现过，则跳过
                continue;
            }
            permutation.insert(nums[i]); // 标记为已出现
            cur_set.emplace_back(nums[i]); // 放到当前序列
            helper(nums, permutation, cur_set, ans); // 递归
            cur_set.pop_back(); 
            permutation.erase(nums[i]);
        }
    }
};