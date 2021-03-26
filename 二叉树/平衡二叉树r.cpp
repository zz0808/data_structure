class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	return height(root) != -1;
    }
    int height(TreeNode* root) {
    	if (root == NULL)
    		return 0;

    	int left = height(root->left); // 左子树的高度，-1表示左子树不平衡
    	int right = height(root->right);

    	if (abs(left - right) > 1 || left == -1 || right == -1)
    		return -1;

    	return max(left, right) + 1;
    }
};