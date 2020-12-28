class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        if (root == p || root == q || root == nullptr)
        	return root;
        // 左子树找到p或q，则左子树返回
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
        	return root;
        if (left != nullptr)
        	return left;
        if (right != nullptr)
        	return right;

        return nullptr;

    }
};