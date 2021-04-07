/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param x int整型 
     * @return ListNode类
     */
    ListNode* partition(ListNode* head, int x) {
        // write code here
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* x1 = dummy1;
        ListNode* x2 = dummy2;

        ListNode* curt = head;

        while (curt != nullptr) {
        	if (curt->val < x) {
        		x1->next = curt;
        		x1 = x1->next;
        	} else {
        		x2->next = curt;
        		x2 = x2->next;
        	}
        	curt = curt->next;
        }
        x2->next = nullptr;
        x1->next = dummy2->next;
        ListNode* ans = dummy1->next;
        delete dummy1;
        delete dummy2;

        return ans;
    }
};
