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
        
        ListNode* tHead = new ListNode(0);
        tHead->next = head;
        
        ListNode* fast = tHead;
        ListNode* slow = tHead;
        
        while (n --)
            fast = fast->next;
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 删除倒数第 n 个节点
        ListNode* rnNode = slow->next;
        slow->next = slow->next->next;
        delete rnNode;
        
        // 释放 tHead 防止内存泄漏
        ListNode* dNode = tHead;
        tHead = tHead->next;
        delete dNode;
        
        return tHead;
    }
};
