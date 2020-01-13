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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;

        queue<pair<TreeNode*, int>> c;
        c.push(make_pair(root, 1));
        while (!c.empty()) {

            pair<TreeNode*, int> cur = c.front();
            c.pop();

            if (cur.first == nullptr)
                continue;
            
            if (cur.second > result.size())
                result.push_back(vector<int>());
            
            result[cur.second - 1].push_back(cur.first->val);

            c.push(make_pair(cur.first->left, cur.second + 1));
            c.push(make_pair(cur.first->right, cur.second + 1));
        }

        return result;
    }
};
