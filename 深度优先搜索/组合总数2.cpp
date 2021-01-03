// 和组合总数相比，候选数字有重复的，并且每个set要唯一，所以要先去重
// 必会
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int>> ans;

    	if (candidates.size() == 0)
    		return ans;

    	vector<int> current_set;

    	sort(candidates.begin(), candidates.end());
    }

    void helper(const vector<int>& candidates, vector<vector<int>>& ans, vector<int>& current_set, 
    	int remain, int start_index) {

    	// 递归出口
    	if (remain == 0) {
    		ans.emplace_back(current_set);
    		return;
    	}

    	for (int i = start_index; i < candidates.size(); i++) {
    		// 第一个数字进去，之后弹出来，那么紧接着的重复数字就不必遍历了
    		if (i > start_index && candidates[i] == candidates[i - 1])
    			continue;

    		if (remain - candidates[i] < 0)
    			break;

    		current_set.emplace_back(candidates[i]);
    		heaper(candidates, ans, current_set, remain - candidates[i], i + 1);
    		current_set.pop_back();
    	}
    }
};