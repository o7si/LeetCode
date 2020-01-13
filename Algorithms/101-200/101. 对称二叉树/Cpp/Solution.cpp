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
    bool isSymmetric(TreeNode* root) {
        
        return isMirror(root, root);
    }
private:
    bool isMirror(TreeNode* lhs, TreeNode* rhs) {
        
        if (lhs == nullptr && rhs == nullptr)
            return true;

        if (lhs == nullptr && rhs != nullptr)
            return false;
            
        if (lhs != nullptr && rhs == nullptr)
            return false;
        
        if (lhs->val != rhs->val)
            return false;

        return isMirror(lhs->left, rhs->right) && isMirror(lhs->right, rhs->left);
    }
};
