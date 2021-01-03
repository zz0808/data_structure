// 给一个二叉树，找到一条最大路径
// O(n)

/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */

class Solution {
public:

    int maxPathSum(TreeNode* root) {
        max_get(root);
        return ans;
    }
    int max_get(TreeNode* root) { // 得到的是通过root的最大路径和
        if (root == nullptr) {
            return 0;
        }
        int left = max(max_get(root->left), 0);
        int right = max(max_get(root->right), 0);
        
        int now_value = root->val + left + right; // 经过root的最大路径
        
        ans = max(ans, now_value);
        
        return root->val + max(left, right);  
    }
 private:
    int ans = INT_MIN;
};







