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
    int sumNumbers(TreeNode* root) {
        
        if (root == nullptr)
            return 0;

        int result = 0;
        
        queue<TreeNode*> c;
        c.push(root);
        while (!c.empty()) {

            TreeNode* cur = c.front();
            c.pop();

            if (cur->left == nullptr && cur->right == nullptr)
                result += cur->val;

            if (cur->left != nullptr) {
                
                cur->left->val += cur->val * 10;
                c.push(cur->left);
            }

            if (cur->right != nullptr) {
                
                cur->right->val += cur->val * 10;
                c.push(cur->right);
            }
        }

        return result;
    }
};
