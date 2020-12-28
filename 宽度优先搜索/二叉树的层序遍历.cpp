class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        /*
			把每层的节点放到一个数组中
        */
        vector<vector<int>> ans;
        if(root == nullptr)
        	return ans;
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
        	size_t sz = q.size();
        	vector<int> level;
        	for (int i = 0; i < sz; i++) {
        		TreeNode* node = q.front();
        		q.pop();
        		level.emplace_back(node);
        		if (node->left != nullptr)
        			q.emplace(node->left);
        		if (node->right != nullptr) 
        			q.emplace(node->right);

        	}
        	ans.emplace_back(level);
        }

        return ans;
    }
};