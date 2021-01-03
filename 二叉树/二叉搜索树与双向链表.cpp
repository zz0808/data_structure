/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 给一个二叉搜索树，生成有序双向链表
// 中序遍历保证是有序的，使用一个pre节点记录前一个节点

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr)
            return nullptr;
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        TreeNode* ans = nullptr;
        while (pRootOfTree != nullptr || !stk.empty()) {
            while (pRootOfTree != nullptr) {
                stk.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            pRootOfTree = stk.top();
            stk.pop();
            if (pre == nullptr) {
                pre = pRootOfTree;
                ans = pRootOfTree;
            } else {
                pre->right = pRootOfTree;
                pRootOfTree->left = pre;
                pre = pRootOfTree;
            }
            pRootOfTree = pRootOfTree->right;
        }
        return ans;
    }
};