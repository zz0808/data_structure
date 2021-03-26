/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists.front();
        }
        auto cmp = [] (ListNode* lhs, ListNode* rhs) {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);
        
        for (auto& l : lists) {
            if (l != nullptr) { // 需要判断
                min_heap.push(l);                
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curt = dummy;
        
        while (!min_heap.empty()) {
            ListNode* temp = min_heap.top();
            min_heap.pop();
            curt->next = temp;
            curt = curt->next;
            if (temp->next != nullptr) { // 否则这里可能有段错误
                min_heap.push(temp->next);
            }
        }
        
        ListNode* ans = dummy->next;
        delete dummy;
        
        return ans;
    }
};
