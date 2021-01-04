/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 和1不同的是要记录每条符合条件的路径，这里使用一个哈希表记录，key:   子节点， value: 父节点
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void get_path(TreeNode* node, vector<vector<int>>& ans) {
        vector<int> temp;
        while (node != nullptr) {
            temp.emplace_back(node->val);
            node = parent[node];
        }
        reverse(temp.begin(), temp.end());
        ans.emplace_back(std::move(temp));
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        queue<int> cur_sum;
        q.emplace(root);
        cur_sum.emplace(root->val);

        while (!q.empty()) {
            TreeNode* node = q.front();
            int now_sum = cur_sum.front();
            q.pop();
            cur_sum.pop();
            if (now_sum == sum && node->left == nullptr && node->right == nullptr) {
                get_path(node, ans);
            }
            if (node->left != nullptr) {
                q.emplace(node->left);
                cur_sum.emplace(node->left->val + now_sum);
                parent[node->left] = node;
            } 
            if (node->right != nullptr) {
                q.emplace(node->right);
                cur_sum.emplace(node->right->val + now_sum);
                parent[node->right] = node;
            }
        }

        return ans;
    }
};


// 解法2: dfs
/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        vector<vector<int> > ans;
        vector<int> path;
        if (root == nullptr)
            return ans;
        
        dfs(ans, path, root, sum);
        
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& path, TreeNode* root, int remain) {
        
        if (root == nullptr)
            return;

        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr ) {
            if (remain == root->val)
                ans.emplace_back(path);
            return;
        }
        if (root->left) {
            dfs(ans, path, root->left, remain - root->val);
            path.pop_back();
        }
        if (root->right) {
            dfs(ans, path, root->right, remain - root->val);
            path.pop_back();            
        }
    }
};

