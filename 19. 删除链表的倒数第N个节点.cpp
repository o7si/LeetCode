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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* eHead = new ListNode(0);
        eHead->next = head;
        
        ListNode* fast = eHead;
        ListNode* slow = eHead;
        
        while (n --)
            fast = fast->next;
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* tNode = slow->next;
        slow->next = slow->next->next;
        delete tNode;
        
        return eHead->next;
    }
};
