/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (vin.size() == 0 || pre.size() == 0) {
            return nullptr;
        }
        return reconstruct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
    
    TreeNode* reconstruct(vector<int> pre,vector<int> vin, int pre_start, int pre_end, int vin_start, int vin_end) {
        if (pre_start > pre_end || vin_start > vin_end) {
            return nullptr;
        }
        int i = 0;
        for (i = vin_start; i <= vin_end; i++) {
            if (vin[i] == pre[pre_start]) {
                break;
            }
        }
//         [1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
        TreeNode* root = new TreeNode(vin[i]);
        
        root->left = reconstruct(pre, vin, pre_start + 1, pre_start + i - vin_start, vin_start, i - 1);
        root->right = reconstruct(pre, vin, pre_start + i - vin_start + 1, pre_end, i + 1, vin_end);
        
        return root;
    }
};
