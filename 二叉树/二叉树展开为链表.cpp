class Solution {
public:
    void flatten(TreeNode* root) {
    	if (root == nullptr)
        	return;
        /*
			将左子树展开为链表后返回链表的最后一个节点
        */
        TreeNode* left_tail = helper(root->left);
        TreeNode* right_tail = helper(root->right);

        if (left_tail != nullptr) {
        	left_tail->right = root->right;
        	root->right = root->left;
        	root->left = nullptr;
        }
        if (right_tail != nullptr)
        	return right_tail;
        if (left_tail != nullptr)
        	return left_tail;
        return root;

    }

};