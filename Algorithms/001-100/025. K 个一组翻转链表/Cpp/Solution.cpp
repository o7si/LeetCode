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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        ListNode* end = dummy->next;
        while (true) {

            for (int i = 0; i < k - 1 && end != nullptr; ++ i)
                end = end->next;
            if (end == nullptr)
                break;
            
            while (cur != end) {

                ListNode* tmp = cur->next;
                cur->next = end->next;
                end->next = pre->next;
                pre->next = tmp;
                cur = tmp;
            }

            for (int i = 0; i < k; ++ i) {

                pre = pre->next;
                cur = cur->next;
                end = end->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;    
        return result;
    }
};
