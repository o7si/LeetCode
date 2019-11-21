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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;

        while (cur != nullptr) {
            
            ListNode* next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
