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
    ListNode* removeElements(ListNode* head, int val) {
     
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        while (pre != nullptr && pre->next != nullptr) {

            ListNode* cur = pre->next;
            if (cur->val != val) {

                pre = pre->next;
            } else {

                pre->next = cur->next;
                delete cur;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
