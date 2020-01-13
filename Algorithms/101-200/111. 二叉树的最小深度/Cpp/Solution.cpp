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
    int minDepth(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> c;
        c.push(make_pair(root, 1));

        int result = 0;
        while (!c.empty()) {

            pair<TreeNode*, int> cur = c.front();
            c.pop();

            if (cur.first == nullptr)
                continue;
            
            if (cur.first->left == nullptr && cur.first->right == nullptr) {
                
                result = cur.second;
                break;
            }

            c.push(make_pair(cur.first->left, cur.second + 1));
            c.push(make_pair(cur.first->right, cur.second + 1));
        }
        return result;
    }
};
