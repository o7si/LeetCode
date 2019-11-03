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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        ListNode* end = dummy->next;
        for (int i = 0; i < m - 1; ++ i) {

            pre = pre->next;
            cur = cur->next;
        }
        for (int i = 0; i < n - 1; ++ i) {

            end = end->next;
        }

        while (cur != end) {

            ListNode* tmp = cur->next;
            cur->next = end->next;
            end->next = pre->next;
            pre->next = tmp;
            cur = tmp;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
