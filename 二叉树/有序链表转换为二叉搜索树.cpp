class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == nullptr) {
    		return nullptr;
    	}
    	ListNode* temp = head;
    	int length = 0;
    	// 1->2->3->null
    	while (temp != nullptr) {
    		length++;
    		temp = temp->next;
    	}
        return buildBSTRecur(&head, length);
    }

    TreeNode* buildBSTRecur(ListNode** head, int n) {
    	if (n <= 0) {
    		return nullptr;
    	}
    	TreeNode* left = buildBSTRecur(head, n / 2);
    	TreeNode* root = new TreeNode((*head)->val);
    	root->left = left;
    	(*head) = (*head)->next;
    	root->right = buildBSTRecur(head,n - n / 2 - 1);

    	return root;
    }
};
