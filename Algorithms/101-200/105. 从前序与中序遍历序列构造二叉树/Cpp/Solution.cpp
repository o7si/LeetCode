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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        this->preorder = preorder;
        this->inorder = inorder;

        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(int preL, int preR, int inL, int inR) {
        
        if (preL > preR)
            return nullptr;

        TreeNode* cur = new TreeNode(preorder[preL]);

        int pos = inL;
        while (pos <= inR && inorder[pos] != preorder[preL])
            ++ pos;

        int cntL = pos - inL;
        int cntR = inR - pos;
        cur->left = build(preL + 1, preL + 1 + cntL - 1, inL, pos - 1);
        cur->right = build(preL + 1 + cntL - 1 + 1, preR, pos + 1, inR);

        return cur;
    }

    vector<int> preorder;
    vector<int> inorder;
};
