/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    // 快慢指针找到中点
    bool isPail(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr; 
        // 把后半部分反转
        ListNode* pre = nullptr;
        ListNode* cur = mid;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        slow = pre;
        fast = head;
        while (fast != nullptr & slow != nullptr) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next, slow = slow->next;
        }
        return true;
    }
};