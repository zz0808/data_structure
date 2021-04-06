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
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        ListNode* l1 = reverse_list(head1);
        ListNode* l2 = reverse_list(head2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* curt = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int d = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            curt->next = new ListNode(d % 10);
            carry = d / 10;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
            curt = curt->next;
        }
        if (carry > 0) {
            curt->next = new ListNode(carry);
            curt = curt->next;
        }
        curt = dummy->next;
        delete dummy;
        ListNode* ans = reverse_list(curt);
        
        return ans;
    }
    
    ListNode* reverse_list(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curt = head;
        
        while (curt != nullptr) {
            ListNode* temp = curt->next;
            curt->next = prev;
            prev = curt;
            curt = temp;
        }
        
        return prev;
    }
};
