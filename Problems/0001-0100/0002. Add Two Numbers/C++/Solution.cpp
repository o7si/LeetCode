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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum = new ListNode(0);
        ListNode* tmp = sum;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            
            int lhs = l1 != nullptr ? l1->val : 0;
            int rhs = l2 != nullptr ? l2->val : 0;
            
            tmp->next = new ListNode((lhs + rhs + carry) % 10);
            carry = (lhs + rhs + carry) / 10;
            
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            tmp = tmp->next;
        }
        
        return sum->next;
    }
};
