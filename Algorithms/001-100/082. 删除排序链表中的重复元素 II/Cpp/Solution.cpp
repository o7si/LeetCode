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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        while (pre->next != nullptr) {

            ListNode* cur = pre->next;
            ListNode* tmp = pre->next;

            int count = 0;
            while (tmp != nullptr && tmp->val == cur->val) {

                ++ count;
                tmp = tmp->next;
            }

            if (count == 1) {

                pre = cur;
            } else {

                while (cur != tmp) {

                    ListNode* del = cur;
                    cur = cur->next;
                    delete del;
                }
                pre->next = tmp;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
