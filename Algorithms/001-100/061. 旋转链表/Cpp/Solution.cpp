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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr)
            return nullptr;

        ListNode* pre = nullptr;
        ListNode* cur = head;

        int listLen = 0;
        while (cur) {

            pre = cur;
            cur = cur->next;
            ++ listLen;
        }
        pre->next = head;

        ListNode* p = head;
        int tmp = listLen - k % listLen;
        while (-- tmp)
            p = p->next;

        ListNode* result = p->next;
        p->next = nullptr;
        return result;
    }
};
