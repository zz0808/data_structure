class Solution {
public:

    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        vector<bool> ans(2);
        ans[0] = helper(root, INT_MIN, INT_MAX);
        ans[1] = helper2(root);
        
        return ans;
    }
    
    bool helper(TreeNode* root, int left_max, int right_min) {
    	if (root == nullptr) {
    		return true;	
		}
		if (root->val <= left_max || root->val >= right_min) {
			return false;
		}
		return helper(root->left, left_max, root->val) && helper(root->right, root->val, right_min);
	}
	
	bool helper2(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			if (node == nullptr) {
				break;
			}
			q.push(node->left);
			q.push(node->right);
		}
		
        while (!q.empty()) {
            if (q.front() == nullptr) {
                q.pop();
            } else {
                return false;
            }
        }
		return q.empty();
	}
};