class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // write code here
        vector<vector<int>> ans;
        if (root == nullptr) {
        	return ans;
		}
		vector<int> now;
		
		dfs(root, ans, now, sum);
		
		return ans;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int>& now, int remain) {
    	if (root == nullptr) {
    		return;
		}
		now.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			if (remain == root->val) {
				ans.push_back(now);
				return;
			}
		}
		
		if (root->left) {
			dfs(root->left, ans, now, remain - root->val);
			now.pop_back();
		}
		
		if (root->right) {
			dfs(root->right, ans, now, remain - root->val);
			now.pop_back();
		}
	}
};