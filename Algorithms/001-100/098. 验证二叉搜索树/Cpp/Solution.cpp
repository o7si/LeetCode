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
    bool isValidBST(TreeNode* root) {
        
        stack<pair<bool, TreeNode*>> c;
        c.push(make_pair(false, root));

        vector<int> order;
        while (!c.empty()) {

            pair<bool, TreeNode*> cur = c.top();
            c.pop();

            if (cur.second == nullptr)
                continue;

            if (!cur.first) {

                c.push(make_pair(false, cur.second->right));
                c.push(make_pair(true, cur.second));
                c.push(make_pair(false, cur.second->left));
            } else {

                if (!order.empty() && cur.second->val <= *--order.end())
                    return false;
                
                order.push_back(cur.second->val);
            }
        }
        return true;
    }
};
