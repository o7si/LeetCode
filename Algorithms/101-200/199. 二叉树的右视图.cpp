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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;

        queue<TreeNode*> c;
        c.push(root);
        while (!c.empty()) {

            TreeNode* node = c.front();
            if (node == nullptr) {

                c.pop();
                continue;
            }

            result.push_back(node->val);

            int size = c.size();
            while (size --) {

                TreeNode* cur = c.front();
                c.pop();

                if (cur == nullptr)
                    continue;

                c.push(cur->right);
                c.push(cur->left);
            }
        }

        return result;
    }
};
