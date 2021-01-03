
class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* dummy = new ListNode(0); // 对于链表发生变化的，添加dummy节点
        dummy->next = head;
        ListNode* pre = dummy;
        
        while (pre != nullptr) {
            pre = reverse_nextK(pre, k);
        }
        
        ListNode* ans = dummy->next;
        delete dummy;
        
        return ans;
    }
    
    ListNode* reverse_nextK(ListNode* head, int k) {
        // before :  head->n1->n2->nk->nk+1
        // after : head->nk->n2->n1->nk+1
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            cur = cur->next;
            if (cur == nullptr)
                return nullptr;
        }
        
        ListNode* nk = cur;
        ListNode* n1 = head->next;
        ListNode* nkp1 = cur->next;
        cur = head->next;
        ListNode* pre = head;
        
        while (cur != nkp1) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        // now : nk->n2->n1->head  nk+1
        // after : head->nk->n2->n1->nk+1
        head->next = nk;
        n1->next = nkp1;
        
        return n1;
    }
};



