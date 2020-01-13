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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (root == nullptr)
            return false;

        queue<TreeNode*> c;
        c.push(root);

        while (!c.empty()) {

            TreeNode* cur = c.front();
            c.pop();

            if (cur->left == nullptr && cur->right == nullptr && cur->val == sum)
                return true;

            if (cur->left != nullptr) {

                cur->left->val += cur->val;
                c.push(cur->left);
            }

            if (cur->right != nullptr) {

                cur->right->val += cur->val;
                c.push(cur->right);
            }
        }
        return false;
    }
};
