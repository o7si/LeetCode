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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack<pair<bool, TreeNode*>> c;
        c.push(make_pair(false, root));
        
        while (!c.empty()) {
            
            pair<bool, TreeNode*> cur = c.top();
            c.pop();
            
            if (cur.second == nullptr)
                continue;
            
            if (!cur.first) {
                
                c.push(make_pair(false, cur.second->right));
                c.push(make_pair(false, cur.second->left));
                c.push(make_pair(true, cur.second));
            } else {
                
                result.push_back(cur.second->val);
            }
        }
        
        return result;
    }
};
