/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left != NULL) {
                q.emplace(node->left);
            }
            if (node->right != NULL) {
                q.emplace(node->right);
            }
        }

        return root;
    }
};