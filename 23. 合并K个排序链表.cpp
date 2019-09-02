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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto compare = [](const ListNode* lhs, const ListNode* rhs) -> bool {
            return lhs->val > rhs->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, function<bool(const ListNode*, const ListNode*)>> c(compare);
        
        for (int i = 0; i < lists.size(); ++ i) {
            
            while (lists[i]) {
                
                c.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        
        ListNode* result = new ListNode(0);
        ListNode* tmp = result;
        while (!c.empty()) {

            tmp->next = c.top();
            c.pop();
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        
        ListNode* eHead = result;
        result = result->next;
        delete eHead;
        
        return result;
    }
};
