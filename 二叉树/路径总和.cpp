

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
	// 使用广度优先遍历
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        queue<TreeNode*> q;
        queue<int> cur_sum; // 为了不破坏二叉树节点值
        q.emplace(root);
        cur_sum.emplace(root->val);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int now_sum = cur_sum.front();
            cur_sum.pop();
            if (now_sum == sum && node->left == nullptr && node->right == nullptr) {
                return true;
            }
            if (node->left != nullptr) {
                cur_sum.emplace(now_sum + node->left->val);
                q.emplace(node->left);
               
            }
            if (node->right != nullptr) {
                cur_sum.emplace(now_sum + node->right->val);
                q.emplace(node->right);
            }
        }
        return false;
    }
    // 使用分治
    bool hasPathSum(TreeNode* root, int sum) { 
        if (root == nullptr) {
            return false;
        }
        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};



