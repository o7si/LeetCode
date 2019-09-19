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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        while (pre->next != nullptr && pre->next->next != nullptr) {

            ListNode* cur = pre->next;
            ListNode* post = pre->next->next;

            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next = post->next;
            post->next = tmp;

            pre = pre->next->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
