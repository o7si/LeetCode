/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (head == nullptr)
            return nullptr;
        
        if (head->next == nullptr)
            return new TreeNode(head->val);

        ListNode* pre = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {

            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;

        TreeNode* cur = new TreeNode(slow->val);
        cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(slow->next);
        return cur;
    }
};
