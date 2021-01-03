// 什么时候使用dfs：
// 	找所有方案
// 	找最优方案(优先考虑动态规划)

// 	组合(O(2^n))
// 	排列
// 必会
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int>> ans;

    	if (candidates.size() == 0)
    		return ans;

    	sort(candidates.begin(), candidates.end());

    	vector<int> current_set;

    	helper(candidates, ans, current_set, target, 0);

    	return ans;

    }

    void helper(const vector<int>& candidates, vector<vector<int>>& ans, vector<int>& current_set, 
    	int remain, int start_index) {

    	// 递归的出口，remain=0表示已经找到一个答案，把这个答案保存并返回
    	if (remain == 0) {
    		ans.emplace_back(current_set);
    		return;
    	}

    	for (int i = start_index; i < candidates.size(); i++) {
    		// 从这里向后都不可能找到满足的，退出循环
    		if (remain - candidates[i] < 0)
    			break;
    		current_set.emplace_back(candidates[i]);
    		// 因为每个数可以重复使用所以传入i而不是i+1
    		helper(candidates, ans, current_set, remain - candidates[i], i);
    		current_set.pop_back();

    	}

    }
};

