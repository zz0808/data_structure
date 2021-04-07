/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        
        return pRoot;
    }
};
