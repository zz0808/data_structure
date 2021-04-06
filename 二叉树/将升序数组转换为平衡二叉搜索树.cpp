/**
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param num int整型vector
     * @return TreeNode类
     */
    TreeNode* sortedArrayToBST(vector<int>& num) {
        // write code here
        if (num.size() == 0) {
            return nullptr;
        }
        return createBST(num, 0, num.size() - 1);
    }
    
    TreeNode* createBST(vector<int>& num, int left, int right) {
        
        if (left > right) {
            return nullptr;
        }
        // left + (right - left) / 2和left + (right - left + 1) / 2 区别在于是左子树深些还
        // 是右子树深些
        int mid = left + (right - left + 1) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = createBST(num, left, mid - 1);
        root->right = createBST(num, mid + 1, right);
        
        return root;
    }
};

