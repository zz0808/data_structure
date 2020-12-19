/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* prev = pListHead;
//         1->2->nullptr
        // 使用快慢指针
        for (int i = 0; i < k; i++) {
            if (prev == nullptr)
                return nullptr;
            prev = prev->next;
        }
        ListNode* cur = pListHead;
        while (prev != nullptr) {
            prev = prev->next;
            cur = cur->next;
        }
        return cur;
    }
};
